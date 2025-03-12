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
    ll a,b;
    cin >> a >> b;
    
   
int v = gcd(a,b);
cout << (1ll*a*b-1ll*v*(a/v)*(b/v))/2+1ll*((a/v)*(b/v)+1)/2*v << nl;
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
