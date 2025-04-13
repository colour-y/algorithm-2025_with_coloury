#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';

struct DSU {
    vector<int> f;
    vector<bool> has_cycle;
    
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        has_cycle.assign(n, false);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            // 合并同一节点或在同一集合，标记环
            has_cycle[fx] = true;
            return false;
        }
        f[fy] = fx;
        // 继承环状态
        has_cycle[fx] = has_cycle[fx] || has_cycle[fy];
        return true;
    }
    
    bool in_cycle(int x) {
        return has_cycle[find(x)];
    }
};

void solve() {
    int n, x;
    cin >> n >> x;
    x--; // 转换为0-based索引
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--; // 转换为0-based索引
    }
    
    DSU dsu(n + 1);
    for (int i = 0; i < n; i++) {
        dsu.merge(i, a[i]);
    }
    
    if (dsu.in_cycle(x)) {
        cout << "Yes" << nl;
    } else {
        cout << "No" << nl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}