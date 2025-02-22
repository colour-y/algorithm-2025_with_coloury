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
ll x,y;
ll n;
cin >> n;
cin >> x >> y;
ll ans = 0;
for (int i = 0; i <= y and i <= n; i += 1) {
    ll m = n - i, a = x + i, b = y - i;
    ll h = min(b, m), pans = h * (a + 1);
    m = min(m - h, a);
    pans += (a + (a - m + 1)) * m / 2;
    ans = max(ans, pans);
  }
cout << ans << nl ;

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
