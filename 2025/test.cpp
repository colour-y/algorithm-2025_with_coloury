#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define deb(...) 114514
#endif

using namespace std;

using LL = long long;
using pii = pair<int, int>;
using pll = pair<LL, LL>;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int N = 3e5 + 10;

void solve() {
    LL n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<LL> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1] + (i != n ? abs(a[i] - a[i - 1]) : 0);
    }
    if (sum[n] <= x) {
        cout << 0 << '\n';
        return;
    }
    auto check = [&](int len) -> bool {
        deque<int> que;
        for (int i = 0; i < len; i++) {
            while (que.size() && a[i] >= a[que.back()]) {
                que.pop_back();
            }
            que.push_back(i);
        }
        for (int l = 0, r = len; r <= n; l++, r++) {
            LL res = 0;
            if (l != 0) {
                res += abs(a[l - 1] - a[que.front()]);
                res += sum[l - 1];
            }
            if (r < n) {
                res += abs(a[r] - a[que.front()]);
                res += sum[n] - sum[r];
            }
            if (res <= x)
                return true;
            if (que.front() == l) {
                que.pop_front();
            }
            if (r < n) {
                while (que.size() && a[r] >= a[que.back()]) {
                    que.pop_back();
                }
                que.push_back(r);
            }
        }
        return false;
    };
    // deb(check(n));
    int l = 2, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}

signed main() {
#ifdef LOCAL
    clock_t tttttttt = clock();
    freopen("in.txt", "r", stdin);
#endif
#ifndef LOCAL
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
    //*****************************************************************
    int t = 1;
    cin >> t;
    while (t--) solve();
//*****************************************************************
#ifdef LOCAL
    cerr << "Time Used: " << fixed << setprecision(3) << (clock() - tttttttt) / (CLOCKS_PER_SEC / 1000.0) << " ms" << endl;
#endif
    return 0;
}