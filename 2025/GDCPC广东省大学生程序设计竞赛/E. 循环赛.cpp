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
ll n,m;
cin >> n >> m;
if(m == 1){
    if(n % 2 == 0){
        cout << 2 << nl;

    }else{
        cout << 1 << nl;
    }
return;
}

if(m <= n / 2 + 1){
    cout << n << nl;
    return;
}
ll ans = 2 * (n - m + 1) ;
if(n % 2 == 1) ans--;
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
