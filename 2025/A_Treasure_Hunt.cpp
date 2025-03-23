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
ll x,y,k;
cin >> x >> y >> k;
k %= x + y;
if(k == 0){
    cout << "NO" << nl;
    return;
}
if(x > k){
    cout << "NO" << nl;
    return;
}else{
    cout << "YES" << nl;
    return;
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
