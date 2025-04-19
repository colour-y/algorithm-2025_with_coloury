#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
#pragma GCC optimize(2)


void solve(){
int n,k;
cin >> n >> k;
vector<array<double,3>> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i][0];
}
for(int i = 0;i < n;i++){
    cin >> a[i][1];
a[i][2] = a[i][1] / a[i][0];
}
sort(all(a),[&](auto x,auto y){
return x[2] > y[2]; 
});
int i = 0;
double ans = 0;
while(k > 0 && i < n){
    double e = a[i][1];
if(k > a[i][0]){
    k -= a[i][0];
    ans += e;
}
else{
    ans += k * e / a[i][0] ;
    k = 0;
}
i++;
}
cout << fixed << setprecision(2) << ans << nl;
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
