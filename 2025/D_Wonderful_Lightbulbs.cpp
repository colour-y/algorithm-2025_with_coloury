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
int n;
cin >> n ;
ll ans = 0,res = 0;
if(n == 1){
    ll x,y;
    cin >> x >> y;
    cout << x << " " << y << nl;
    return;
}

for(int i = 0;i < n;i++){
    ll x,y;
cin >> x >> y;
    ans ^= x;
res ^= (x + y);
}
cout << ans << " " << res - ans << nl;

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
