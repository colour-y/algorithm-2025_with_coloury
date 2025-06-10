#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
string a = "SCCPC";  

void solve() {
    int n;                     // 点数
    cin >> n;
    string s;                  // 节点挂的字母
    cin >> s;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    /* -------- 预处理：每个节点相邻的 'S' 和 'C' 的数量 -------- */
    vector<int> cntS(n), cntC(n);
    for (int x = 0; x < n; ++x)
        for (int y : adj[x]) {
            if (s[y] == 'S') ++cntS[x];
            else if (s[y] == 'C') ++cntC[x];
        }

    /* -------- 枚举中心节点（必须是字母 'C'） -------- */
    ll ans = 0;
    for (int x = 0; x < n; ++x) if (s[x] == 'C') {
        ll left  = 0;  // 选 “C→S” 两步臂 的方案数
        ll right = 0;  // 选 “P→C” 两步臂 的方案数

        for (int y : adj[x]) {
            if (s[y] == 'C') {           // 左臂第一跳必须是 'C'
                left += cntS[y];         // 第二跳必须是 'S'
            } else if (s[y] == 'P') {    // 右臂第一跳必须是 'P'
                int c = cntC[y] - 1;     // 第二跳必须是 'C'，去掉中心 x 自身
                if (c > 0) right += c;
            }
        }
        ans += left * right;             // 左臂 × 右臂 组合
    }

    cout << ans << nl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
