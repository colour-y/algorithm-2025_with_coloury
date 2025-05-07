#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), val(n), ok(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            val[i] = a[i] + (i + 1);
        }

     
        ok[n - 1] = val[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            ok[i] = min(val[i], ok[i + 1]);
        }


        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int e = i + 1;
            res += ok[i] - e;
        }

        cout << res << '\n';
    }

    return 0;
}
