#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> a;
    vector<int> b;

    DSU(int size, int N) {
        parent.resize(size);
        a.resize(size, 0);
        b.resize(size, 0);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < size; ++i) {
            if (i < N) {
                a[i] = 1;
                b[i] = 0;
            } else {
                a[i] = 0;
                b[i] = 1;
            }
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (a[x] + b[x] < a[y] + b[y]) {
            swap(x, y);
        }
        parent[y] = x;
        a[x] += a[y];
        b[x] += b[y];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, P, Q;
    cin >> N >> M >> P >> Q;

    int total = N + M;
    DSU dsu(total, N);

    for (int i = 0; i < P; ++i) {
        int x, y;
        cin >> x >> y;
        x--; // 转换为0-based索引
        y--;
        dsu.merge(x, y);
    }

    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        x = -x - 1; // 转换为B公司的索引
        y = -y - 1;
        dsu.merge(N + x, N + y);
    }

    int ming = 0; // 小明的索引是0
    int hong = N; // 小红的索引是N（B公司的第一个元素）
    dsu.merge(ming, hong);

    int root = dsu.find(ming);
    int a_count = dsu.a[root];
    int b_count = dsu.b[root];

    cout << min(a_count, b_count) << endl;

    return 0;
}