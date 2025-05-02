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
vector<ll> a(32);
int k = 0;
ll x;
cin >> x;
for(int i = 0;i < 31;i++){
    ll y ;
    cin >> y;
    if(y < x )k++;
}

if(k == 31) cout << 1 << nl;
else if(k >= 27) cout << 2 << nl;
else if(k >= 13) cout << 4 << nl;
else if(k >= 6) cout << 8  << nl;
else if(k >= 2) cout << 16 << nl;
else cout << 32 << nl;

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
