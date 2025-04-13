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





void solve(){
    ll ans = 0;
for(int i = 2;i * i * 2 <= 23333333333333;i++){

for(int j = i;;j++){
if(isPrime(i) && isPrime(j)){
    ll x = i * i + j * j;
    if(x >= 2333 && x <= 23333333333333) ans++;
    if(x > 23333333333333) break;
}
cout << ans << nl;
}
cout << ans << nl;
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
