#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
constexpr int K = 60;
vector<vector<ll>> dp(100,vector<ll>(100,1e18));
ll cnt =0 ;
void init(){
    dp[0][0] = 0;
    for(ll i = 1;i<=60;i++){
        auto ndp = dp;
        // for(ll i = 0;i<60;i+=1){
        //     for(ll j =0;j<60;j+=1){
        //         ndp[i][j] = 1e18;
        //     }
        // }
        for(ll j = 0;j<60;j+=1){
            for(ll k = 0;k<60;k++){
                if(i + j < 60) ndp[j + i][k] = min(ndp[j + i][k] ,dp[j][k] + (1ll<<i));
                if(i + k < 60) ndp[j][k + i] = min(ndp[j][k + i] ,dp[j][k] + (1ll<<i));
            }
        }
        swap(dp,ndp);
        // break;
    }
    // cout<<dp[0][1]<<endl;
}
  void solve(){
    ll x, y;cin>>x>>y;
for(int i = 0;i < 60;i++){
    for(int j = 0;j < 60;j++){
        cout << dp[i][j] << " ";
    }
    cout << nl;
}
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  
init();

int t = 1;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
