#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int n_ = 0) { init(n_); }
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Fenwick<ll> fen(n);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        fen.add(i, a[i]);
    }
    int k = 0;
    ll res = 0;
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            x--;
            ll e = y - a[x];
            fen.add(x, e);
            a[x] = y;
        } else {
            ll r = fen.sum(y);
            ll l = fen.sum(x - 1);
            ll ans = (r / 100) - (l / 100);
            k++;
            res ^= ans * k;
        }
    }
    cout << res << nl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}