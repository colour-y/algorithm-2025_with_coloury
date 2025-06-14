#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

struct DSU
{
    vector<int> f, siz;
    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x)
    {
        return siz[find(x)];
    }
};

struct edg {
    int u, v;
    ll w;
};




void solve() {
    int n, m;
    cin >> n >> m;

    vector<edg> a(m);
    for (auto &e : a) cin >> e.u >> e.v >> e.w;

    sort(all(a), [](auto& x,auto &y) { return x.w < y.w; });

    DSU dsu(n + 1);                      
    vector<ll> vis(n + 1, LLONG_MAX);     
    ll ans = LLONG_MAX;                   

    for (auto &e : a) {
        int x = dsu.find(e.u);
        int y = dsu.find(e.v);

        if (x != y) {                      
            ll mi = min({vis[x], vis[y], e.w});
            dsu.merge(x, y);              
            int c = dsu.find(x);          
            vis[c] = mi;
        } else {                            
            int c = x;
            vis[c] = min(vis[c], e.w);
        }

        if (dsu.same(1, n)) {             
            int root = dsu.find(1);
            ans = min(ans, vis[root] + e.w);
        }
    }
    cout << ans << nl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
      solve();
    }
    return 0;
}
