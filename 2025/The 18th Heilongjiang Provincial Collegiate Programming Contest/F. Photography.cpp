#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Memo: key -> max sum
    // key 格式：(y << 40) | (x << 20) | mask
    // 假设 n <= 20，这样 mask 用低 20 位，x 用接着的 20 位，y 用更高的位。
    unordered_map<uint64_t, ll> memo;

    function<ll(int,int,int)> dfs = [&](int x, int y, int mask) -> ll {
        // 剩一步，直接取当前节点权值
        if (y == 1) return a[x];

        // 组合成一个 64 位的 key
        uint64_t key = ( (uint64_t)y << 40 )
                     | ( (uint64_t)x << 20 )
                     | (uint64_t)mask;
        auto it = memo.find(key);
        if (it != memo.end()) 
            return it->second;

        ll best = a[x];
        // 枚举下一跳
        for (int e : adj[x]) {
            if (mask & (1 << e)) continue;    // 已访问就跳过
            best = max(best, a[x] + dfs(e, y - 1, mask | (1 << e)));
        }
        return memo[key] = best;
    };

    ll ans = 0;
    // 从每个节点开始，最多走 5 步（也就是 5 个顶点）
    for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(i, 5, 1 << i));
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
