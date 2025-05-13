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
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for (int b = 0; b < 31; b++) {
        if (!((k >> b) & 1LL)) continue;
        vector<int> e;
        e.reserve(n);
        for (int i = 0; i < n; i++) {
            if ((a[i] >> b) & 1LL) e.push_back(i);
        }
        if (e.size() == n) continue; 
        ll mx = 0;
        ll m = e.size();
        for (int j = 0; j < m; j++) {
            ll l = e[j];
            ll r = e[(j + 1) % m];
            ll lo = ( r - l + n ) % n;
            ll hi = max(0LL, lo - 1);
            mx = max(mx, hi);
        }
        ans = max(ans, mx);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
