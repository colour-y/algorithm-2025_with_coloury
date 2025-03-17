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
ll n,k;
cin >> n >> k;
if(k >= n){
    cout << 1 << nl;
    return;
}
if(n % 2 == 1){
    if(k % 2 == 1){
        ll ans =1 + (n - k) / (k - 1);
        if((n - k) %  (k - 1) != 0) ans++;
        cout <<  ans << nl;
        
    }else{
        ll ans = 1 + (n - k + 1) / k;
        if((n - k + 1) % k != 0) ans++;
        cout << ans << nl;
        
    }
}else{
    if(k % 2 == 1){
        ll ans =  n / (k - 1);
        if(n % (k - 1) != 0) ans++;
        cout << ans << nl;

    }else{
        ll ans = n /k;
        if(n % k != 0) ans++;
        cout << ans << nl;
    }
}
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
