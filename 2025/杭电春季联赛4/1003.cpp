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
ll k,b,c,v;
cin >> k >> b >> c >> v;
ll ans = 0,led = 0,u,l,r;
for(int i = 59;i >= 0;i--){
    if(v >> i & 1){
        u = (led ^ c) & ((1ll << 60) - (1ll << i));
        l = u - 1;
        r = u + ((1ll << i ) - 1);
        if(r >= b)
        ans += (r - b ) / k + 1;
        if(l >= b) 
        ans -= (l - b) / k + 1;
    }
    led |= (v >> i & 1) << i ;

}

if((v ^ c ) - b >= 0 && ((v ^ c ) - b ) % k == 0 ) ans++;
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
