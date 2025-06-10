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
    cin >> n >> m;
    vector<ll> a(m);
    for (auto &e : a) {
        cin >> e;
    }

    ranges::sort(a);

// for(auto e : a){
//     cout << e << " "; 
// }
// cout << nl;

    vector<ll> l(n + 2), r(n + 2);
    for (int i = 0; i <= n / 2; i++) {
        l[2 * i]  = a[i];
l[2 * i + 1] = a[m - 1 - i];
        r[2 * i] = a[m - 1 - i];
        r[2 * i + 1] = a[i];
        // cout << 2 * i + 1 << nl;
        // cout << i << " " << m - i - 1 << nl;
        // cout << a[i] << " " << a[m - i - 1] << nl;
    }

// for(auto e : r){
//     cout << e << " "; 
// }
// cout << nl;

    for (int i = 0; i < n; i++) {
        cout << l[i] << ' ' << r[i] << ' ' << l[i] << ' '
             << r[i] << ' ' << l[i] << ' ' << r[i] << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
