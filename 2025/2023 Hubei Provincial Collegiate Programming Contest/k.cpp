#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;

  #define all(x) (x).begin(), (x).end()

constexpr int p = 998244353;


  i64 mul(i64 a, i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
    c += p;
    }
    return c;
    }
    i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
    if (b % 2) {
    res = mul(res, a, p);
    }
    }
    return res;
    }
    


  void solve(){
int n,m;
cin >> n >> m;
for(int i = 1;i <= m;i++){
    if(i == 1){
        cout << 1 << " ";
    }else if(i == m){
        cout <<  0 << " ";
    }else{
cout << power(m - i,n,p) * power(power(m - 1,p - 2,p),n,p) % p << " ";
    }
}
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
