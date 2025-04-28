#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 3), b(n + 3), suf(n + 3);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    b[1] = a[1];
    for (int i = 2; i <= n; i++) {
        b[i] = max(b[i - 1], a[i]);
    }
  
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }

    for (int k = 1; k <= n; k++) {
        int x = n - k + 2; 

        ll ans = b[x - 1] + suf[x];
        cout << ans;
        if (k < n) cout << ' ';
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
