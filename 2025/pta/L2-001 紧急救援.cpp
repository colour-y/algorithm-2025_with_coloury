#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  vector<int> a(n);
  for (auto &k : a) cin >> k;


  vector<vector<array<int, 2>>> adj(n); 

  for (int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      adj[x].push_back({y, z});  
adj[y].push_back({x,z});
  }
auto dfs = [&](this auto&& dfs ,int x,int y,int ans,int k) -> int{
if(!k){
  return 0;
}
if(x == y){
  return ans;
}


return ans;
};
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
