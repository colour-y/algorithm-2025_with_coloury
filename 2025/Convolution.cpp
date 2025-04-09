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
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<vector<ll>> I(3010, vector<ll>(3010));
    vector<vector<ll>> IQ(3010, vector<ll>(3010));
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> I[i][j];
            ll x = I[i][j];            
            IQ[i][j] = x + IQ[i - 1][j] + IQ[i][j - 1] - IQ[i - 1][j - 1];
        }
    }
    auto query =[&](ll x1, ll y1, ll x2, ll y2) -> ll{
        ll ans = IQ[x2][y2] - IQ[x1 - 1][y2] - IQ[x2][y1 - 1] + IQ[x1 - 1][y1 - 1];
        return ans; 
    };
    
    ll res = 0;
    for(int i = 1; i <= k; i ++){
        for(int j = 1; j <= l; j ++){
            res += abs(query(i, j, n - k + i, m - l + j));
        }
    }
    cout << res << '\n';
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