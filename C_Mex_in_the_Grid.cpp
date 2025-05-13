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
        vector<vector<int>> a(n, vector<int>(n));

      
        int hi = 0,lo = n - 1, l = 0, r = n - 1;
        int k = n * n - 1;
        while (hi <= lo && l <= r) {
            for (int j = l; j <= r; j++)
                a[hi][j] = k--;
            hi++;
            for (int i = hi; i <=lo; i++)
                a[i][r] = k--;
            r--;
            if (hi <=lo) {
                for (int j = r; j >= l; j--)
                    a[lo][j] = k--;
               lo--;
            }
            if (l <= r) {
                for (int i =lo; i >= hi; i--)
                    a[i][l] = k--;
                l++;
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << (j + 1 < n ? ' ' : nl);
            }
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
