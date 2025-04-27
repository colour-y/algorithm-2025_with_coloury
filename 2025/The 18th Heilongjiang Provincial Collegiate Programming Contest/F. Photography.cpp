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
int n,m;
cin >> n >> m;
vector<ll> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
vector adj(n,vector<int>());
for(int i = 0;i < m;i++){
    int x,y;
    cin >> x >> y;
x--,y--;
adj[x].push_back(y);
adj[y].push_back(x);
} 
vector<int> vis(n);


auto dfs = [&](this auto&& dfs,int x,int y,vector<int> cph) -> ll{
ll res = 0;
if(y == 1) return a[x];
cph[x] = 1;

for(auto e : adj[x]){
    if(cph[e]) continue;

    res = max(res, dfs(e,y - 1,cph) + a[x]);
    // cout << e << " " << res << nl;

}
res = max(res,a[x]);
return res;
};
ll ans = 0;

for(int i = 0 ;i < n;i++){
    

ans = max(ans,dfs(i,5,vis));

}

cout << ans << nl;

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
