#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define int long long

std::vector<int> b;
std::map<std::pair<int, int>, int> mp;
int dfs(int x, int k)
{
    if (!k)
    {
        return 1;
    }
    if (!x)
    {
        return 0;
    }
    if (mp.count({x, k}))
    {
        return mp[{x, k}];
    }
    int now = *std::prev((std::upper_bound(begin(b), end(b), x)));
    return mp[{x, k}] = dfs(x - now, k - 1) + dfs(now - 1, k);
}
void solve()
{
    int l, r, k;
    std::cin >> l >> r >> k;
    std::cout << dfs(r, k) - dfs(l - 1, k) << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    for (int i = 1; i <= 1e18; i = i * 4 + 1)
    {
        b.push_back(i);
    }
    int T;
    std::cin >> T;
    while (T--)
    {
        solve();
    }
}