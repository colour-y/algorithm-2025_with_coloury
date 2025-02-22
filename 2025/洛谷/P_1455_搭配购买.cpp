#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

struct DSU {
    vector<int> f, siz, sum_c, sum_d;

    DSU(int n, const vector<int>& c, const vector<int>& d) {
        init(n, c, d);
    }

    void init(int n, const vector<int>& c, const vector<int>& d) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        sum_c = c;
        sum_d = d;
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        f[y] = x;
        siz[x] += siz[y];
        sum_c[x] += sum_c[y];
        sum_d[x] += sum_d[y];
        return true;
    }
};

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<int> c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> d[i];
    }

    DSU dsu(n, c, d);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        dsu.merge(u, v);
    }

    vector<pair<int, int>> items;
    for (int i = 0; i < n; ++i) {
        if (dsu.find(i) == i) {
            items.emplace_back(dsu.sum_c[i], dsu.sum_d[i]);
        }
    }

    vector<int> dp(w + 1, 0);
    for (auto& item : items) {
        int cost = item.first;
        int val = item.second;
        if (cost > w) continue;
        for (int j = w; j >= cost; --j) {
            dp[j] = max(dp[j], dp[j - cost] + val);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}