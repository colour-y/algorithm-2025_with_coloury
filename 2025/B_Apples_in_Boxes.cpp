#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = long long;
using i32 = int;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &e : a) cin >> e;
    ranges::sort(a);
    ll mx = a.back();
    ll mi = a[0];
    ll d = mx - mi;
    if (d > k) {
        ll b = (n >= 2) ? max(a[n-2], mx - 1) : (mx - 1);
        ll c = b - mi;
        ll d = mi - 1;
        ll e = mx - d;
        if (c > k && e > k) {
            cout << "Jerry" << nl;
            return;
        }
    }
    ll su = reduce(a.begin(), a.end(), 0LL);
    cout << (su % 2 ? "Tom" : "Jerry") << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}