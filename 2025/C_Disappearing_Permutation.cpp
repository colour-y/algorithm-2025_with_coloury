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
int n;
cin >> n;
vector<int> a(n),b(n);
for(auto &e : a){
    cin >> e;
    e--;
}

for(auto &e : b){
    cin >> e;
    e--;
}
int ans = 0;
DSU dsu(n + 1);

vector<int> memo(n);
for(int i = 0;i < n;i++){
    int x = a[b[i]];
    if(memo[x]){
        cout << ans << " ";
        
    }
    else if(x == b[i]){
        memo[x] = 1;
        ans++;
        cout << ans << " ";
        
    }else {
        int y = x;
while(!memo[y]){
memo[y] = 1;
ans++;
y = a[y];

}
cout << ans << " ";
    }


}
cout << nl;
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
