#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned ll;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
  int n, m;
  cin >> n >> m;
  
  ll mx = INT_MIN, mi = INT_MAX;
  ll mxk = INT_MIN, mik = INT_MAX;
  
  for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      ll sum = (ll)x + y;
      ll k = (ll)x - y;
      
      if (sum > mx) mx = sum;
      if (sum < mi) mi = sum;
      if (k > mxk) mxk = k;
      if (k < mik) mik = k;
  }
  
  ll e = INT_MAX;
  for (int j = 0; j < m; ++j) {
      int a, b;
      cin >> a >> b;
      ll su = (ll)a + b;
      ll kk= (ll)a - b;
      
      ll mxx = max(mx - su, su - mi);
      ll mxy = max(mxk - kk, kk - mik);
      ll ans= max(mxx, mxy);
      
      if (ans< e) {
          e = ans;
      }
  }
  
  cout << e << '\n';
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
