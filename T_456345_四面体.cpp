#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(0);

    ll n;
    cin >> n;  

    if (n == 0) {
        cout << 1 << nl;
        return 0;
    }
    if (n == 1) {
        cout << 0 << nl;
        return 0;
    }

    ll f0 = 1;  
    ll f1 = 0;   
    ll f2 = 0;   

    for (ll i = 2; i <= n; i++){

        f2 = (2 * f1 % MOD + 3 * f0 % MOD) % MOD;
   
        f0 = f1;
        f1 = f2;
    }


    cout << f1 << nl;
    return 0;
}
