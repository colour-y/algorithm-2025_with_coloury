#include <bits/stdc++.h>

const int mod = 998244353;

const int N = 1e5 + 5;

int n, a[N], b[N];

void run() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> b[i];
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int res = 1;
        for (int j = 30; j >= 0; j--)
            if (b[i] >> j & 1) {
                res += 1 << __builtin_popcount(a[i] & ((1 << j) - 1));
                if (a[i] >> j & 1 ^ 1) {
                    res--;
                    break;
                }
            }
        ans = 1ll * ans * res % mod;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) run();
    return 0;
}