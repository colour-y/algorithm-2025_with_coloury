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
int a,b,c;
cin >> a >> b >> c;
int ans = a;
ans += b / 3;
b %= 3;


if( b != 0 && b + c < 3){
    cout << -1 << nl;
    return;
}
b += c;
ans += b / 3;
if(b % 3 != 0) ans++;
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
