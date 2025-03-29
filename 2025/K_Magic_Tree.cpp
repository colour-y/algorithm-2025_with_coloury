#include <bits/stdc++.h>

#define int long long

const int p = 998244353;
void solve()
{
    int x;
    std::cin >> x;
    int ans = 1;
    x--;
    for (int i = 1; i <= x; ++i)
    {
        ans = ans * 2 % p;
    }
    std::cout << ans << '\n';
}
signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        solve();
    }
}