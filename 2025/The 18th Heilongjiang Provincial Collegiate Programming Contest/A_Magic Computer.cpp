#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
const int MOD = 998244353;

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = i128(a) * a % p) {
    if (b % 2) {
    res = i128(res) * a % p;
    }
    }
    return res;
    }
    //a的b次方除余p
    
void solve(){
    int n;
    cin  >> n;
cout << power(2,n - 1,MOD) << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
