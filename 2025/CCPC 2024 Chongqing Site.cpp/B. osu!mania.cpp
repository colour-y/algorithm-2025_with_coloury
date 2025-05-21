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
ld a,b,c,d,e,f;
cin >> a >> b >> c >> d >> e >> f;
ld res = (300 * a + 300 * b + 200 * c + 100 * d + 50 * e) ;
ld k = (300 * (a + b + c + d + e + f));
cout << fixed << setprecision(2) << res / k * 100  << "% ";
ld ans = (320 * a + 300 * b + 200 * c + 100 * d + 50 * e) / (320 * (a + b + c + d + e + f)) - 0.8;
if(ans <= 0){
    cout << 0 << nl;
    return;
}
// ld q = ans * 5 * n * 100;
i64 pp = std::round(std::max(0.L, (320 * a + 300 * b + 200 * c + 100 * d + 50 * e) / 320.L / (a + b + c + d + e + f ) - 0.8L) * 5 * n + 1e-8);
// cout  << ll(ans * 5 * n ) +  (ll(round(ans * 5 * n * 100)) / 10 % 10 >= 5 ? 1 : 0 )<< nl;
cout <<pp<< nl; 

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
