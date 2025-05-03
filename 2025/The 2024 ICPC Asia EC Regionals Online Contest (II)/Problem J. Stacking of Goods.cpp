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
cin >> n;
vector<array<ll,3>> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i][0] >> a[i][1] >> a[i][2]; 
}

sort(all(a),[&](auto x,auto y){
return x[0] * y[2] > y[0] * x[2];
}); 

// for(int i = 0;i < n;i++){
//     cout << a[i][0] << nl;
// }

ll ans = 0;
ll k = 0;
for(int i = 0;i < n;i++){
if(ans == 0){
    ans += a[i][1];
    k += a[i][0];
continue;
}

ll x = a[i][1] - k * a[i][2];
if(x < 0) x = 0;
ans += x;
k += a[i][0];
}

cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}
