#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
using ll = long long;
using ld = long double;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()
static const ll MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll k = 0;
    for (ll x : a) k += x;
    vector<ll> b(n+1, 0);
    for (int i = 1; i <= n; i++) {
        b[i] = b[i-1] + a[i-1];
    }
    ll mid = (k + 1) / 2;
    int x = lower_bound(b.begin() + 1, b.begin() + n, mid) - b.begin();
    ll c = 0;
    for (int dr = -1; dr <= 0; dr++) {
        int r = x + dr;
        if (r >= 1 && r < n) {
            ll x = b[r];
            ll y = x * (k - x);
            if (y > c) c = y;
        }
    }
    ll ans = (ll)(c % MOD);
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
