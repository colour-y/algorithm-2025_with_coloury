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
int n,m;
cin >>n >> m;
vector<array<int,3>> a(m);
for(int i = 0;i < m;i++){
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
sort(a.begin(),a.end(),[&](auto &x,auto &y){
return x[2] < y[2];
});
DSU df(n + 1);
for(int i = 0;i < m;i++){
    if(!df.same(a[i][0],a[i][1]))
    df.merge(a[i][0],a[i][1]);
    if(df.size(1) == n){
        cout << a[i][2] << nl;
        return;
    }
}
cout << -1 << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
