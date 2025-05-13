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
vector<vector<int>> adj(n + 1);
for(int i = 0;i < m;i++){
    int x,y;
    cin >> x >> y;
    
    adj[x].push_back(y);
    adj[y].push_back(x);
}

vector<int> vis(n + 1);
auto dfs = [&](auto &&dfs,int x) -> void {
    if(vis[x]) return;
    vis[x] = 1;
for(auto c : adj[x]){
  
    if(c > x){
        dfs(dfs,c);
        // cout << c << nl;
    }
}
};
dfs(dfs,0);
for(int i = 1;i <= n;i++){
    if(!vis[i]){
        cout << 0 << nl;
        return;
    }
}
cout << 1 << nl;


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
