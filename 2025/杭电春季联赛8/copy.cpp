#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int N = 200005;
const int INF = 0x3f3f3f3f;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        int k, c, d, e, f;
        cin >> k >> c >> d >> e >> f;
        int tot = 0;
        for (int i = 1; i < 10007; i++) {
            int t = i * i * i * c + i * i * d + i * e + f;
            vector<int> vec;
            while (t) {
                vec.push_back({t % 27});
                t /= 27;
            }
            if ((int)vec.size() > k) continue;
            bool ok = 0;
            for (auto x : vec) {
                if (x == 0) {
                    ok = 1;
                    break;
                }
            }
            if (ok) continue;
            int m = 1, S = 0;
            for (auto x : vec) {
                S += x * m;
                S %= 10007;
                m = m * 10 % 10007;
            }
            if (S == i) tot++;
        }
        cout << tot << endl;
    }
    return 0;
}
