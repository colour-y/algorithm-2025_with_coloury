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
if(k % 2 ==  1){
    cout << 0 << nl;
    return;
}
int r = k / 2;
int p = n / r;
if(p % 2 == 0) p--;
int s = (p + 1) / 2;
ll res = 1LL * ( 1 + p ) * s /2 * r;
res = 1LL * n * s - res ;
cout << res << nl;
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
