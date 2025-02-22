#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

ll power(ll a, ll b) {
ll res = 1;
for (; b; b /= 2, a = ll(a) * a) {
if (b % 2) {
res = ll(res) * a;
}
}
return res;
}
//a的b次方除余p



void solve(){
ll n,m;
cin >> n >> m;
if(m == 1 || n == 1 ){
cout << 1 << nl;
return;
}
int i;
for(i = 1;;i++){
    if(power(m,i) == n){
        cout << i << nl;
        return;
    }
else if(power(m,i) > n){
    break;
}

}
ll k = power(m,i);
if(abs(k / m - n) <= k - n){
    i--;
}
if(i == 0) i++;
cout << i << nl;

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
