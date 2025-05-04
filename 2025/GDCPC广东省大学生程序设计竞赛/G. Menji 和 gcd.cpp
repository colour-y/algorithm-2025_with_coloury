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
ll l,r;
cin >> l >> r;
ll ans = 0;
auto check = [&](ll x) -> void{
  if(!x) return;
  if(r / x - (l - 1) / x > 1) ans = max(ans,x);
};
for(int i = 1;i <= 1e6;i++){
check(i);
check(r / i);
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
