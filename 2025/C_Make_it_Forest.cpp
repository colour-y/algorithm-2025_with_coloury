#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    DSU dsu(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    int C = 0;
    for (int i = 1; i <= N; ++i)
        if (dsu.find(i) == i)
            ++C;

    int ans = M - (N - C);
    cout << max(0, ans) << '\n';

    return 0;
}