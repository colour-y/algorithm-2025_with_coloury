#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()
#define N 1000000
int i, j, k, n, m, t, a[N + 50], p[N + 50];
ll res;
void solve()
{

    cin >> n;
    res = 1ll * n * (n + 1) / 2;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (k = 1; k <= 10; k++)
    {
        map<int, int> mp;

        for (i = 1; i <= n; i++)
            p[i] = p[i - 1] + (a[i] <= k ? -1 : 1);

        j = 0;
        for (i = 1; i <= n; i++)
        {
            if (a[i] == k)
            {
                for (; j < i; j++)
                    mp[p[j]]++;
            }
            res -= mp[p[i]];
        }
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
