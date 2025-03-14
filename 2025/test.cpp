#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = unsigned long long;

namespace fox {
template <class T>
constexpr T pow(T x, ll y) {
    T r = 1;
    for (; y > 0; y /= 2, x = x * x)
        if (y % 2 == 1) r = x * r;
    return r;
}
} // namespace fox

struct Scanner {
    FILE* stream;
    Scanner(FILE* s) : stream(s) {}
    char buf[1 << 20], *l = buf, *r = buf;
    bool flush() { l = buf; r = l + fread(buf, 1, 1 << 20, stream); return l == r; }
    void get(char& c) { c = l == r && flush() ? ' ' : *l++; }
    friend Scanner& operator >>(Scanner& in, char& c) { return in.get(c), in; }
    friend Scanner& operator >>(Scanner& in, char* s) {
        for (in.get(s[0]); isspace(s[0]); in.get(s[0]));
        for (int i = 0; !isspace(s[i]) || (s[i] = '\0'); i++) in.get(s[i + 1]);
        return in;
    }
    friend Scanner& operator >>(Scanner& in, std::string& s) {
        char c;
        for (in.get(c); isspace(c); in.get(c));
        for (s = ""; !isspace(c); in.get(c)) s += c;
        return in;
    }
    template <class T> requires std::is_integral_v<T>
    friend Scanner& operator >>(Scanner& in, T& x) {
        char c, f = '+';
        for (in.get(c); !isdigit(c); in.get(c))
            if constexpr (std::is_signed_v<T>) f = c;
        for (x = 0; isdigit(c); in.get(c)) x = x * 10 + c - '0';
        if constexpr (std::is_signed_v<T>) x = f == '-' ? -x : x;
        return in;
    }
    template <class T> requires std::is_floating_point_v<T>
    friend Scanner& operator >>(Scanner& in, T& x) {
        std::string s; in >> s; x = std::stod(s);
        return in;
    }
    template <class T, class U>
    friend Scanner& operator >>(Scanner& in, std::pair<T, U>& a) {
        return in >> a.first >> a.second;
    }
    template <class T, size_t S>
    friend Scanner& operator >>(Scanner& in, std::array<T, S>& a) {
        for (int i = 0, n = S; i < n; i++) in >> a[i];
        return in;
    }
    template <class T>
    friend Scanner& operator >>(Scanner& in, std::vector<T>& a) {
        for (int i = 0, n = a.size(); i < n; i++) in >> a[i];
        return in;
    }
};

struct Printer {
    FILE* stream;
    Printer(FILE* s) : stream(s) {}
    char buf[1 << 20], *l = buf, *r = buf + (1 << 20) - 1;
    int format = 0, precision = 15;
    ~Printer() { flush(); }
    void flush() { fwrite(buf, 1, l - buf, stream); l = buf; }
    void put(const char& c) { *l++ = c; if (l == r) flush(); }
    friend Printer& operator <<(Printer& out, const char& c) { return out.put(c), out; }
    friend Printer& operator <<(Printer& out, const char* s) {
        for (int i = 0; s[i] != '\0'; i++) out.put(s[i]);
        return out;
    }
    friend Printer& operator <<(Printer& out, const std::string& s) {
        for (int i = 0, n = s.size(); i < n; i++) out.put(s[i]);
        return out;
    }
    template <class T> requires std::is_integral_v<T>
    friend Printer& operator <<(Printer& out, T x) {
        static char s[40];
        static int i = 0;
        if (x == 0) { out.put('0'); return out; }
        if constexpr (std::is_signed_v<T>) x = x < 0 ? out.put('-'), -x : x;
        while (x > 0) s[++i] = x % 10 + '0', x /= 10;
        while (i > 0) out.put(s[i--]);
        return out;
    }
    template <class T> requires std::is_floating_point_v<T>
    friend Printer& operator <<(Printer& out, T x) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(out.precision) << x;
        return out << oss.str();
    }
    template <class T, class U>
    friend Printer& operator <<(Printer& out, const std::pair<T, U>& a) {
        return out << a.first << " \n"[out.format > 1] << a.second;
    }
    template <class T, size_t S>
    friend Printer& operator <<(Printer& out, const std::array<T, S>& a) {
        out << a[0];
        for (int i = 1, n = S; i < n; i++) out << " \n"[out.format > 1] << a[i];
        return out;
    }
    template <class T>
    friend Printer& operator <<(Printer& out, const std::vector<T>& a) {
        if (!a.empty()) out << a[0];
        for (int i = 1, n = a.size(); i < n; i++) out << " \n"[out.format > 0] << a[i];
        return out;
    }
};

Scanner in(stdin);
Printer out(stdout), err(stderr);

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const ll inf = 1e18;

const int N = 1e5 + 5;

int n, m;
std::vector<ll> f[4][N];
std::vector<int> a[N], b[N];

void run() {
    in >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
            in >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        b[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
            in >> b[i][j];
        f[0][i].resize(m + 1);
        f[1][i].resize(m + 1);
        f[2][i].resize(m + 1);
        f[3][i].resize(m + 1);
        for (int j = 1; j <= m; j++)
            f[0][i][j] = f[1][i][j] = f[2][i][j] = f[3][i][j] = inf;
    }
    std::priority_queue<std::tuple<ll, int, int, int>, std::vector<std::tuple<ll, int, int, int>>, std::greater<std::tuple<ll, int, int, int>>> que;
    que.push({0, 2, 1, 1});
    f[2][1][1] = 0;
    ll ans = inf;
    while (!que.empty()) {
        auto [d, k, i, j] = que.top();
        que.pop();
        if (d != f[k][i][j]) continue;
        for (int t = 0; t < 4; t++)
            if (t != k && f[t][i][j] > d + b[i][j]) {
                f[t][i][j] = d + b[i][j];
                que.push({f[t][i][j], t, i, j});
            }
        d += a[i][j];
        if (i == n && j == m && k == 0)
            ans = std::min(ans, d);
        i += dx[k]; j += dy[k];
        if (i >= 1 && j >= 1 && i <= n && j <= m && f[k][i][j] > d) {
            f[k][i][j] = d;
            que.push({f[k][i][j], k, i, j});
        }
    }
    out << ans << "\n";
}

int main() {
#ifdef SULFOX
    freopen("#.in", "r", stdin);
    freopen("#.out", "w", stdout);
#endif
    int t = 1;
    in >> t;
    for (int i = 0; i < t; i++) { run(); }
    return 0;
}