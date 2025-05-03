#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

i64 power(i64 a, i64 b)
{
    i64 res = 1;
    for (; b; b /= 2, a = i128(a) * a)
    {
        if (b % 2)
        {
            res = i128(res) * a;
        }
    }
    return res;
}

void solve()
{
    ll n;
    cin >> n;
    if (n % 4 == 0)
    {
        cout << "NO" << nl;
        return;
    }


    n--;




    vector<int> ans(32, -1);
    ans[31] = 1;
    if (n == 0)
    {
        int k = 0;
        for (auto e : ans)
        {
            cout << e << " ";
            k++;
            if (k % 8 == 0)
                cout << nl;
        }
        return;
    }
    ll x = 1;
    int k = -2;
    while (x <= n)
    {
        x *= 2;
        k++;
    }
    x /= 2;

 


    while (n)
    {

    
        if (n == 1)
        {

            ans[0] = 0;
            break;
        }

        if (n >= x)
        {
            n -= x;
            ans[k] = 1;
        }
        else
        {
            x /= 2;
            k--;
        }
    }
    cout << "YES" << nl;
    int c = 0;
    for (auto e : ans)
    {
        cout << e << " ";
        c++;
        if (c % 8 == 0)
            cout << nl;
    }
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
