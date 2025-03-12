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
    vector<array<int, 2>> a(n);

    for (int i = 0; i < n; i++)
    {
        char c1, c2;
        int k1, k2;
        cin >> c1 >> a[i][0];
        cin >>  c2 >> a[i][1];
        if (c1 == '+')
            a[i][0] = -a[i][0];
        if (c2 == '+')
            a[i][1] = -a[i][1];
    }





    int k1,k2;
    int ans = 1, res = 1;
    for (int i = 0; i < n; i++)
    {
        
if(a[i][0] < 0) k1 = a[i][0];
if(a[i][1] < 0) k2 = a[i][1];


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
