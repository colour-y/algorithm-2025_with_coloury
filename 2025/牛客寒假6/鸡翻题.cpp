#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
ll x,y;
cin >> x >> y;
y -= 2 * x + 1;
if(y == 0){
    cout << "YES" << nl;
    return;
}

if(abs(y) % 4 == 0){
    cout << "YES" << nl;
    return;
}else{
    cout << "NO" << nl;
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
