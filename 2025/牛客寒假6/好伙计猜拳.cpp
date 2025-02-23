#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve () {
    int n, x, y;
    cin >> n >> x >> y;

    vector<array<int, 2>> a(n + 1);
    vector<array<int, 2>> b(n + 1);
    a[0][0] = a[0][1] = b[0][0] = b[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i][0] >> a[i][1];
        b[i] = a[i];
        std::swap(b[i][0], b[i][1]);
    }

    constexpr int INF = 1e18;
    vector<std::array<int, 2>> dp(n + 1, {INF, INF});

    dp[0][0] = dp[1][0] = 0;
    dp[1][1] = y;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][0] >= a[j][0] && a[i][1] >= a[j][1]) {
                dp[i][0] = min<int>(dp[i][0], dp[j][0] + (i - j - 1) * x);
            }
            if (a[i][0] >= b[j][0] && a[i][1] >= b[j][1]) {
                dp[i][0] = min<int>(dp[i][0], dp[j][1] + (i - j - 1) * x);
            }
            if (b[i][0] >= a[j][0] && b[i][1] >= a[j][1]) {
                dp[i][1] = min<int>(dp[i][1], dp[j][0] + (i - j - 1) * x + y);
            }
            if (b[i][0] >= b[j][0] && b[i][1] >= b[j][1]) {
                dp[i][1] = min<int>(dp[i][1], dp[j][1] + (i - j - 1) * x + y);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, min(dp[i][0] + (n - i) * x, dp[i][1] + (n - i) * x));
    }

    std::cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t -- ) {
        solve();
    }

    return 0;
}