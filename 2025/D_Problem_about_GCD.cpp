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
ll l,r,g;
cin >> l >> r >> g;
l = (l + g - 1) / g;
r /= g;

for(ll d = r - l;d >= 0;d--){
    for(ll a = l;a + d <= r;a++){
        ll b = a + d;
        if(gcd(a,b) == 1){
            cout << a * g << " " << b * g << nl;
       return;
        }
    }
}
cout << -1 << " " << -1 << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
