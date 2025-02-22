#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
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


void solve(){
int n, h, r;
    cin >> n >> h >> r;
    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<bool> is_low(n), is_high(n);
    for (int i = 0; i < n; ++i) {
        is_low[i] = (z[i] - r <= 0);
        is_high[i] = (z[i] + r >= h);
    }

    DSU dsu(n);
    ll limit = 4LL * r * r;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll dx = x[i] - x[j], dy = y[i] - y[j], dz = z[i] - z[j];
            ll dist_sq = dx*dx + dy*dy + dz*dz;
            if (dist_sq <= limit) {
                dsu.merge(i, j);
            }
        }
    }

    unordered_set<int> high_roots;
    for (int i = 0; i < n; ++i) {
        if (is_high[i]) {
            high_roots.insert(dsu.find(i));
        }
    }

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (is_low[i] && high_roots.count(dsu.find(i))) {
            found = true;
            break;
        }
    }

    cout << (found ? "Yes" : "No") << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
