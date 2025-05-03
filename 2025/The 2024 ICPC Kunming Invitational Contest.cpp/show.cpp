#include <bits/stdc++.h>

using i64 = long long;

i64 gcd(i64 x, i64 y) {
    if (x == 0) return y;
    if (y == 0) return x;
    return std::gcd(x, y);
}

void Solve() {
    int n;
    i64 K;
    std::cin >> n >> K;

    std::vector<i64> a(n + 1); 
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    
    std::vector<i64> g(n + 1), suf(n + 2);
    for (int i = 1; i <= n; ++i) g[i] = gcd(g[i - 1], a[i]);
    for (int i = n; i > 0; --i) suf[i] = gcd(suf[i + 1], a[i]);
    
    i64 ans = g[n];
    for (int i = 1; i <= n; ++i) 
        if (g[i] != g[i - 1]) {
            i64 gc = g[i - 1];
            for (int j = i; j <= n; ++j) {
                gc = gcd(gc, a[j] + K);
                ans = std::max(ans, gcd(gc, suf[j + 1]));
            }
        }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int ti = 1; ti <= t; ++ti) {
        // std::cerr << "Solve : " << ti << '\n';
        Solve(); 
    }

    return 0;
}