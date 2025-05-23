#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
const ll inf = 1e9 + 7;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n,m,q;
cin >> n >> m >> q;
vector<vector<int>> adj(n + 1);
vector<vector<ll>> w(n + 1);
for(int i = 0;i < m;i++){
    int u,v;
    ll d;
    cin >> u >> v >> d;
    adj[u].push_back(v);
    w[u].push_back(d);
}

vector<vector<ll>> dp(n + 1,vector<ll>(32));
for(int i = 1;i <= n;i++){
    dp[i][0] = 1;
}

for(int i = 1;i < 32;i++){
    for(int j = 1;j <= n;j++){
        for(int k = 0;k < adj[j].size();k++){
            dp[j][i] = max(dp[j][i],dp[adj[j][k]][i - 1] * w[j][k]);
        }
        dp[j][i] = min(inf,dp[j][i]);
    }
}


while(q--){
    int u;
    ll x;
    cin >> u >> x;
    cout << upper_bound(dp[u].begin() + 1,dp[u].end(),x ) - dp[u].begin() << nl;
}

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
