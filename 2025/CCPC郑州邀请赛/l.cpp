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
int n,m;
cin >> n >> m;
vector<int> a(m);

for(int i = 0 ;i < m;i++){
    cin >> a[i];
}

vector<ll> dp(m + 1,1E18);
dp[0] = 0;
for(int i = 0 ;i < m;i++){
    for(int j  = i + 1;j <= m && j - i <= 500 ;j++){
        dp[j] = min(dp[j],dp[i] + a[j - 1] + 1LL* (j - i) * (j - i) * (j - i) * (j - i)) ;
    }
}
cout << dp[m] << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
