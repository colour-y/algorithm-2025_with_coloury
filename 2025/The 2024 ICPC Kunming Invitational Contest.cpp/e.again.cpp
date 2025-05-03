#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define ai64(x) (x).begin(), (x).end()

void solve()
{
    int n;
    i64 k;
    cin >> n >> k;

    vector<i64> a(n + 1), pre(n + 1), suf(n + 1);
    suf[n] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = __gcd(pre[i - 1], a[i]);
        // cout << pre[i] << nl;
    }
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }

    i64 ans = suf[0];

    for (int i = 0; i < n; i++)
    {
        i64 c;
        if (i == 0)
            c = a[0] + k;
        else
            c = pre[i - 1];

          if(i != 0 && c == pre[i]) continue; 


        for (int j = i; j < n; j++)
        {
            c = __gcd(c, a[j] + k);
            // if(i == n - 1){
            //     cout << a[j] + k << nl;
            // }
            if (j == n - 1)
                ans = max(ans, c);
            else
                ans = max(ans, __gcd(c, suf[j + 1]));
            // cout << c << " " << suf[j + 1]  << " " << ans << nl;
        }
    }

    cout << ans << nl;
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
