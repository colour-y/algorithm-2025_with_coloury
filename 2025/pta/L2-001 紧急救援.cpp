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

  vector<vector<int>> adj(n);
  map<pair<int,int>,int> mp;
  for(int i = 0;i < m;i++){
    int x,y,z;
    cin >> x >> y >> z;
    if(x > y) swap(x,y);
    adj[x].push_back(x);
    adj[y].push_back(y);
    mp[{x,y}] = z;
  }
vector<int> ans;
  auto dfs = [&](this auto&& dfs,int x,int y,int ans) -> int {
    if
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
