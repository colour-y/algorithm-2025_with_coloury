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
int n,st,en;
cin >> n >> st >> en;
st--;
en--;

vector<vector<int>> adj(n);
for(int i = 1;i < n;i++){
    int u,v;
    cin >> u >> v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> q;
q.push_back(en);
vector<bool> vis(n);
vis[en] = 1;
for(int i = 0;i < n;i++){
    int x = q[i];
    for(auto y : adj[x]){
        if(!vis[y]){
            vis[y] = 1;
            q.push_back(y);
        }
    }
}
reverse(all(q));
for(auto x : q){
    cout << x + 1 <<  " \n"[x == q.back()];
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
