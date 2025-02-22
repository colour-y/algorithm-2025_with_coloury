#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    if (n < k) {
        cout << 0 << endl;
        return 0;
    }
    ll fact = 1;
    for (int i = 2; i <= k; ++i) {
        fact = fact * i % MOD;
    }
    ll m = (n - k + 1); // Number of overlapping windows needed
    ll ans = mod_pow(fact, m, MOD);
    cout << ans << endl;
    return 0;
}