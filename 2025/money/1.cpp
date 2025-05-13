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
    ll a, b;
    cin >> a >> b;
    ll e = a + 4*b;
    ll S = sqrt(e);
    if (S*S != e) {
        cout << "NO" << nl;;
        return;
    }
    ll k = S / 2;
    if (b <= k*k) cout << "YES" << nl;
    else cout << "NO" << nl;
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
