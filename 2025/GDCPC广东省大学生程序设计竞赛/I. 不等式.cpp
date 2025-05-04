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
  
  using pii = pair<int, int>;

  const int lim = (int)1e9;
  const int N = 2e5+5;
  int n, m, A[N], deg[N];
  vector<pii> vec[N];
  vector<int> G[N];
  int que[N], ed=-1, fr=0;
  
  void solve(){
int n,m;
cin >> n >> m;
for(int i = 1;i <= m;i++){
int x,y,z;
cin >> x >> y >> z;
vec[x].push_back({y,z});
G[y].push_back(x),G[z].push_back(x);
deg[x] += 2;

}
for(int i = 1;i <= n;i++){
    A[i] = -1;
}
for(int i = 1;i <= n;i++){
    if(deg[i] == 0) que[++ed] = i;
}
bool ok = 1;
while(fr <= ed){
    int x = que[fr++];
    A[x] = 1;
    for(auto [y,z] : vec[x]) A[x] = max(A[x] ,A[y] + A[z]);
    if(A[x] > lim) {
        ok = 0;
        break;
    }
    for(auto v : G[x]){
        --deg[v];
        if(deg[v] == 0) que[++ed] = v;
    } 
}
int ans = 0;
for(int i = 1;i <= n;i++){
    ans += A[i];
    if(A[i] == -1 || ans > lim) {
        ok = 0;
        break;
    }
}
if(!ok) cout << -1 << nl;
else cout << ans << nl;

}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}
