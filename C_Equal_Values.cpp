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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    vector<int> c(n + 1);

    vector<int> e;
    e.reserve(n);
    int k = 1;
    c[a[0]] = 1;
    e.push_back(a[0]);
    b[a[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            k++;
        }
        else
        {
            k = 1;
        }
        if (!c[a[i]])
        {
            c[a[i]] = 1;
            e.push_back(a[i]);
        }
        b[a[i]] = max(b[a[i]], k);
    }
    if (e.size() == 1 && b[e[0]] == n)
    {
        cout << 0 << nl;
    }
    else
    {
        ll ans = LLONG_MAX;
        for (int v : e)
        {
            ll q = (ll)(n - b[v]) * v;
            ans = min(ans, q);
        }
        cout << ans << nl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
