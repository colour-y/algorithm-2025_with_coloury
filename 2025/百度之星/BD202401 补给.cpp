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
ll k;
cin >> n >> k;
vector<array<ll,2>> a(n);
for(auto &e : a){
    cin >>  e[0] >> e[1];
} 
sort(all(a),[&](auto x,auto y){
    if(x[0] + x[1] == y[0] + y[1]){
        return x[0] > y[0];
    }
return x[0] + x[1] < y[0] + y[1];
});
ll mx = 0;
int ans = 0;
int ok = 1;
for(int i = 0;i < n;i++){
k -= a[i][0] + a[i][1];

mx = max(mx,a[i][0]);
if(k < 0 && ok){
    k += mx / 2;
    ok = 0;
}else if(k < 0 && !ok){ 
    break;
}
if(k >= 0) ans++;

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
