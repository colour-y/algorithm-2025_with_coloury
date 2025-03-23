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

void solve(){
int n,q;
cin >> n >> q;
DSU dsu(n + 1);
int home[n + 1], id[n + 1], pos[n + 1];
for (int i = 1; i <= n; i++) {
    home[i] = id[i] = pos[i] = i;
}
while(q--){
    int k;
    cin >> k;
    if(k == 1){
        int x, y;
        std::cin >> x >> y;
        int u = pos[x], v = pos[y];
        dsu.merge(u, v);
        id[dsu.find(u)] = x;
        pos[x] = dsu.find(u);
    }else if(k == 2){
        int i, x;
        std::cin >> i >> x;
        home[i] = pos[x];
    }else if(k == 3){
        int x, y;
        std::cin >> x >> y;
        int u = pos[x], v = pos[y];
        id[u] = y; id[v] = x;
        pos[y] = u; pos[x] = v;
    }else{
        int i;
        std::cin >> i;
        std::cout << id[dsu.find(home[i])] << "\n";
    }
}
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
