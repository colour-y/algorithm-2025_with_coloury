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
int n,k;
cin >> n >> k;
if(k == 1){
    cout << n << nl;
    return;
}
if(n <= k){
    cout << 1 << nl;
    return;
}
int ans = 0;
if(k % 2 == 0){
    n -= k / 2;
    ans++;
    ans += (n / ((k / 2) + 1) );
}
else{
    ans += (n / ((k / 2) + 1));
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
