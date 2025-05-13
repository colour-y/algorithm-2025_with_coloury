#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()
int n, m;
void solve()
{
    // 解决示例具体方法

    cin >> n >> m;
    if (n * m <= 2)
    {
        cout << n * m << nl;
        return;
    }
    if (m < n)
    {
        swap(m, n);
    }

    if (n == 1)
    {
        cout << m / 2 + 1 << nl;
        return;
    }

    cout<<(n+m+1)/2;
    }

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
