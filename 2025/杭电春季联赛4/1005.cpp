#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()

void solve() {
    ll P;
    int n, k;
    cin >> P >> n >> k;
    vector<int> a, b;

    for (int i = 0; i < n; ++i) {
        int t, p;
        cin >> t >> p;
        if (t == 0) {
            a.push_back(p);
        } else {
            b.push_back(p);
        }
    }

    // 修改点1：折扣券按升序排列
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    vector<ld> c(1, 1.0L);
    for (int d : a) {
        c.push_back(c.back() * (d / 10.0L));
    }

    vector<ll> e(1, 0);
    for (int r : b) {
        e.push_back(e.back() + r);
    }

    int x = a.size();
    int y = b.size();
    // 修改点2：枚举i的范围
    int mi = max(0, k - y);
    int mx = min(x, k);
    ld res = numeric_limits<ld>::max();

    for (int i = mi; i <= mx; ++i) {
        int j = k - i;
        if (j < 0 || j >= (int)e.size()) continue;

        ld f = (ld)P * c[i];
        ll g = e[j];
        ld cost = f - g;
        cost = max<ld>(cost, 0.0L);
        if (cost < res) {
            res = cost;
        }
    }

    cout << fixed << setprecision(2) << res << nl;
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