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
ll x;
cin >> x;
if(x < 5){
    cout << -1 << nl;
return;
}
ll ans = 0;
bool ok1 = 0,ok2 = 0;
ll k  = 1;
while(x > 1 && (!ok1 || !ok2)){
    if(x & 1 && !ok1){
ok1 = 1;
ans += k;

    }else if(!(x & 1) && !ok2){
        ok2 = 1;
        ans += k;
 
    }
    k *= 2;
    x >>= 1;
}
if(!ok1 || !ok2) cout << -1 << nl;
else
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
