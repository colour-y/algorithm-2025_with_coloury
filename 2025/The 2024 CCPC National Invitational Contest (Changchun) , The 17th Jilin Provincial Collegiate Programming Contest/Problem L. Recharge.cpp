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
ll k,x,y;
cin >> k >> x >> y;
if(k == 1){
    cout << x + y << nl;
    return;
}
ll ans = 0;
int ok = k % 2;
if(ok == 1){
ll e = y / (k / 2);
if(e <= x){
    x -= e;
    y -= e * (k / 2);
    ans += e;
}else{
    ans += x;
    y -= (k / 2) * x;
    x = 0;
}
// cout <<x << " " << y << nl;
if(x != 0){
    x += y * 2;
ans += x / k;
// cout << -1 << nl;
}else{
    k++;
    ans += y * 2 / k;
    // cout << y * 2 / k;
}


}else{
    ans +=( y * 2 + x ) / k;
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
