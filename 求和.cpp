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
ll n;
cin >> n;
if(n == 1 || n == 2){
    cout << n << nl;
    return;
}
ll ans = 2;
vector<ll> dp(n + 1);
dp[1] = 1;
dp[2] = 1;
for(int i = 3;i <= n;i++){
    dp[i] = dp[i - 1] + dp[i - 2];
    ans += dp[i];
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
