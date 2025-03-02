#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  int dx[2] = {1,0},dy[2] = {0,1};


void solve(){
int n,m;
cin >> n >> m;
vector a(n,vector<int>(m));
for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
        cin >> a[i][j];
    }
}

vector dp(n,vector<int>(m));
auto check = [&](int d){
    dp.assign(n,vector(m,0));
    dp[0][0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(a[i][j] % d == 0){
                if(i){
                    dp[i][j] |= dp[i - 1][j];
                }
                if(j){
                    dp[i][j] |= dp[i][j - 1];
                }
            }
        }
    }
    return dp[n - 1][m - 1];
};
int ans = 0;
for(int d = 1;d * d <= a[0][0];d++){
    if(a[0][0] % d == 0){
        if(check(d)){
            ans = max(ans,d);
        }
        if(check(a[0][0] / d)){
            ans = max(ans,a[0][0] / d);
        }
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
