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
int n,m;
cin >> n >> m;
if(m >= n){
    cout << 1 << nl;
    return;
}
ll k = 1;
ll ans = 0;
auto b = m;
while(m--){
    k *= 2;
    ans = k * 2;
    if((k - 1) >= n){
        break;
    }
}

if(k - 1 < n ){
    cout << -1 << nl;
    return;
}
k = 1;
while(b--){
    if(b == 0) break;
k *= 2;
ans = (n - k + 1) / b;
if(ans >= 2 / k && ans <= k){
    if((n - k + 1) % b != 0) ans++;
    cout << ans << nl;
    return;
}
}
cout << k / 2 << nl;
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
