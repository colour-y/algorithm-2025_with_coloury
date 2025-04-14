#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()


  bool isPrime(ll num) {
    if (num <= 3) {
        return num > 1;
    }
    // 不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    ll sqr = sqrt(num);
    for (int i = 5; i <= sqr; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

i64 power(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b /= 2, a = i128(a) * a ) {
    if (b % 2) {
    res = i128(res) * a;
    }
    }
    return res;
    }



void solve(){
ll n;
cin >> n;
for(int i = 2;i <= n;i++){
    for(int j = i;j <= n;j++){
if(isPrime(power(i,j) + power(j,i)) ){
cout << i << " " << j << " " << power(i,j) + power(j,i)<< nl;
}
    }
}
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
