#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin() + 1, (x).end()
void solve(){
int n;
cin >> n ;
vector<vector<array<int,2>>> adj(n + 1);
for(int i = 1;i < n;i++){
    int x,y;
    int k; 
    cin >> x >> y >> k;
    k %= 2;
    adj[x].push_back({y,k});
    adj[y].push_back({x,k});

}
int root;
for(int i = 1;i <= n;i++){
    if(adj[i].size() == 1){
        root = i;
        break;
    }
}
vector<bool> b(n + 1, false);
vector<int> dis(n + 1);


function<void(int,int,int)> dfs = [&](int u,int f,int c){
    b[u] = 1;
    dis[u] = c;
    for(auto [v,w] : adj[u]){
        if(v != f){
            dfs(v,u,(c + w) % 2);
        }
    }
};
dfs(root,0,0);




ll x = count(all(dis), 0), y = count(all(dis), 1);
auto ans = [&] (ll x) {
    return x * x * x;
};
cout << ans(x) + ans(y) << endl;


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
