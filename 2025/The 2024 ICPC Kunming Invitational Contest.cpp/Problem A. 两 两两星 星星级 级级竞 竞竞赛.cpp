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
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> p(n);
    iota(all(p), 0);
    vector<ll> a(n);
    vector<array<ll, 2>> sum(n);
    vector b(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
            if (b[i][j] != -1)
            {
                sum[i][0] += b[i][j];
            }
            else
            {
                sum[i][1]++;
            }
        }
    }

    sort(all(p), [&](auto x, auto y)
         {
if(a[x] == a[y]) return sum[x][0]  < sum[y][0];
return a[x] < a[y]; });
    ll e = 0;
    for (int i = 0; i < n; i++)
    {
        int x = p[i];

        if (i != 0)
        {
            int y = p[i - 1];
            if (a[x] != a[y])
                e++;
               
        }

        if (e == 0)
        {
            e = sum[x][0];
            for (int j = 0; j < m; j++)
            {
                if (b[x][j] == -1)
                    b[x][j] = 0;
            }
        }
        else
        {
            if (sum[x][0] > e)
            {
                e = sum[x][0];
                for (int j = 0; j < m; j++)
                {
                    if (b[x][j] == -1)
                        b[x][j] = 0;
                }
            }
            else
            {
                ll y = e - sum[x][0];
                for (int j = 0; j < m; j++)
                {
                    if (b[x][j] == -1)
                    {
                        if (y >= k)
                            b[x][j] = k;
                        else
                            b[x][j] = y;
                        y -= b[x][j];
                    }
                }
                if (y > 0)
                {
                    
// for(int l = 0;l < n;l++){
// cout << p[l] << " ";
// cout << sum[p[l]][0] << nl;
// }

// cout << nl;

                    cout << "No" << nl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << nl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
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
