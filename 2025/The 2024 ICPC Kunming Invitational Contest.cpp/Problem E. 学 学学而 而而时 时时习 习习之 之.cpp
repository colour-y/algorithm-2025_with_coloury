#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n + 1), pre(n + 1), suf(n + 1);
    suf[n] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = gcd(pre[i - 1], a[i]);
        // cout << pre[i] << nl;
    }
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = gcd(suf[i + 1], a[i]);
    }

    ll ans = suf[0];
ll y = 0;
    for (int i = 0; i < n; i++)
    {
        ll c;
        if (i == 0)
            c = a[0] + k;
        else
            c = pre[i - 1];

            if(!y && c == y) continue;
            y = c;


        for (int j = i; j < n; j++)
        {
            c = gcd(c, a[j] + k);
            // if(i == n - 1){
            //     cout << a[j] + k << nl;
            // }
            if (j == n - 1)
                ans = max(ans, c);
            else
                ans = max(ans, gcd(c, suf[j + 1]));
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
