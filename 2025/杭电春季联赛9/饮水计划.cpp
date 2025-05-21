#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

   
    vector<vector<ll>> mn(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        ll cur = a[i];
        for (int j = i; j < n; j++) {
            cur = min(cur, a[j]);
            mn[i][j] = cur;
        }
    }

    vector<vector<ll>> res(n, vector<ll>(n + 1, 0));


    for (int i = 0; i < n; i++) {
        int p = n - 1;     
        ll mx = 0;          
        for (int l = i; l >= 0; l--) {
            mx = max(mx, a[l]);

            while (p > i && mn[i+1][p] < mx) 
                p--;
            if (p <= i) 
                break;
            res[l][i+1]++;
            res[l][p+1]--;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            res[i][j] += res[i][j-1];
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << res[x][y] << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
