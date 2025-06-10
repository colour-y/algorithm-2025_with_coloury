#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve()
{
int n,m;
cin >> n >> m;

vector<int> b(n);

for(auto &e : b)
{
    cin >> e;
}

vector<vector<array<int,2>>> adj(n);
for(int i = 0 ;i < m;i++){
    int s,t,w;
    cin >> s >> t >> w;
    s--,t--;
    adj[s].push_back({t,w});
}

auto check = [&](int x){
    vector<int> dp(n,-1);
    dp[0] = min(x,b[0]);
    for(int i = 0;i < n;i++){
        for(auto [j,w] : adj[i]){
            if(dp[i] >= w){
                dp[j] = max(dp[j],min(x,dp[i] + b[j]));
            }
        }
    }
    return dp[n - 1] >= 0;
};
int lo = 0,hi = 1e9 + 7;
while(lo < hi){
    int x = (lo + hi) / 2;
    if(check(x)){
        hi = x;
    }else{
        lo = x + 1;
    }

}

if(lo == 1e9 + 7){
    cout << -1 << nl;
    return;
}

cout << lo << nl;
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

