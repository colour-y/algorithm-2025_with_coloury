#include <bits/stdc++.h>

using i64 = long long;

const int P = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        ++k;

        std::vector<int> dp(n + 1), pw(n + 1);
        pw[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[i] = 5ll * pw[i - 1] % P;
        }

        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = 1ll * dp[i - 1] * 26 % P;
            if (i >= k) {
                if (i == k) dp[i] = (dp[i] + P - pw[k]) % P;
                else dp[i] = (dp[i] + P - 21ll * pw[k] % P * dp[i - k - 1] % P) % P;
            }
        }

        std::cout << dp[n] << std::endl;
    }
    return 0;
}