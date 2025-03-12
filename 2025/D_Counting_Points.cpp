#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), r(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> r[i];
    
    map<int, vector<pair<ll, ll>>> mp;
    
    for (int i = 0; i < n; ++i) {
        ll xi = x[i];
        ll ri = r[i];
        for (int y = 0; y <= ri; ++y) {
            ll s = ri * ri - (ll)y * y;
            if (s < 0) continue;
            ll dx = sqrt(s);
            while (dx * dx > s) dx--;
            while ((dx + 1) * (dx + 1) <= s) dx++;
            ll x = xi - dx;
            ll k = xi + dx;
            mp[y].emplace_back(x, k);
        }
    }
    
    ll ans = 0;
    for (auto& [y, f] : mp) {
        sort(f.begin(), f.end());
        vector<pair<ll, ll>> q;
        for (auto& e : f) {
            ll l = e.first, rr = e.second;
            if (q.empty()) {
                q.emplace_back(l, rr);
            } else {
                auto& tt = q.back();
                if (l <= tt.second + 1) {
                    ll rl = min(tt.first, l);
                    ll lr = max(tt.second, rr);
                    q.pop_back();
                    q.emplace_back(rl, lr);
                } else {
                    q.emplace_back(l, rr);
                }
            }
        }
        ll cnt = 0;
        for (auto& p : q) {
            cnt += p.second - p.first + 1;
        }
        if (y == 0) {
            ans += cnt;
        } else {
            ans += 2 * cnt;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}