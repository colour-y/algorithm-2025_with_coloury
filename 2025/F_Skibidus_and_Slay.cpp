#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n;
cin >> n;
vector<int> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
    a[i]--;
}

string ans(n,'0');
vector<vector<int>> adj(n);
for(int i = 1;i < n;i++){
    int u,v;
    cin >> u >> v;
    u--,v--;
    if(a[u] == a[v]){
        ans[a[u]] = '1';
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
   

}
vector<int> vis(n,-1);
for(int x = 0;x < n;x++){
    for(auto y : adj[x]){
        int v = a[y];
        if(vis[v] == x){
            ans[v] = '1';
        }
        vis[v] = x;
    }
}
cout << ans << nl;

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
