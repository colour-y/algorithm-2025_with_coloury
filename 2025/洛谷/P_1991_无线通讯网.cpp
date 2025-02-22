#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

struct DSU {
    vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int s, p;
    cin >> s >> p;
    vector<pair<int, int>> points(p);
    for (int i = 0; i < p; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    vector<tuple<double, int, int>> edges;
    for (int i = 0; i < p; ++i) {
        for (int j = i + 1; j < p; ++j) {
            double dx = points[i].first - points[j].first;
            double dy = points[i].second - points[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            edges.emplace_back(dist, i, j);
        }
    }

    sort(all(edges), [](const auto& a, const auto& b) {
        return get<0>(a) < get<0>(b);
    });

    DSU dsu(p);
    int components = p;
    double maxD = 0.0;

    for (const auto& edge : edges) {
        if (components <= s) break;
        double d = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
        if (!dsu.same(u, v)) {
            dsu.merge(u, v);
            components--;
            maxD = d; // 边已排序，当前d是最大的
        }
    }

    cout << fixed << setprecision(2) << maxD << nl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // 根据题目输入要求，调整为单组输入
    // 原题输入包含多组测试数据，但实际样例显示一组输入后接0结尾
    // 此处保持原题给出的main函数结构，但根据问题描述，应处理单组输入
    solve();
    return 0;
}