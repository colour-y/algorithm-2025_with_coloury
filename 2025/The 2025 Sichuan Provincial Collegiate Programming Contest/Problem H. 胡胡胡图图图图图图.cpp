#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve()
{
ll x,y,l,r;
cin >> x >> y >> l >> r;
ll ans = 0;
ll k1 = abs(l - x),k2 = abs(r - y);

if(k1 > k2) swap(k1,k2);

if(k1 == 0 && k2 == 0){
    cout << 0 << nl;
    return;
}



ans = k2 / 2 + k2 % 2;
if(k1 == 0 && ans == 1){
    cout << 2 << nl;
    return;
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

