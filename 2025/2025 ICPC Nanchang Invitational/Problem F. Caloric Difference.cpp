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
ld r0,c0,l,r;
ld p;
cin >> r0 >> c0 >> p >> l >> r;
map<int,ld> mp;
for(int i = 0;i < k;i++){
    int x; 
    ld y;
    cin >> x >> y; 
   
    mp[x] = y;

} 
ld ans = 0;
ld c = p * c0 + (1 - p ) * r0;
ans += c;
ld t = 0;
if(mp[1]) t = mp[1];
else t = l;
ans -= t;
for(int i = 2;i <= n;i++){
    c = p * c + (1 - p) * t;
    ans += c;
    if(mp[i]) t = mp[i];
    else t = l;
    ans -= t;
}
cout  << fixed << setprecision(10) << ans << nl;
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
