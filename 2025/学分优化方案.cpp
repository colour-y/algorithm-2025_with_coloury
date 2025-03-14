#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;

  #define all(x) (x).begin(), (x).end()


ll cph(ll m) {
    ll res = m;
    for (ll p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            res = res / p * (p - 1);
            while (m % p == 0) {
                m /= p;
            }
        }
    }
    if (m > 1) {
        res = res / m * (m - 1);
    }
    return res;
}

int main() {
    ll C, M;
    cin >> C >> M;
    ll d = gcd(C, M);
    ll m = M / d;
    cout << cph(m) << endl;
    return 0;
}