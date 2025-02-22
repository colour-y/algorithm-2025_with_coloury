#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

#define all(x) (x).begin(), (x).end()

// 自定义的 Info 结构，用于表示线段树中的节点信息
struct Info {
    ll sum = 0; // 区间的总和

    // 重载加号操作符，用于合并两个节点的区间信息
    Info operator+(const Info &other) const {
        return {sum + other.sum};
    }
};

template <class Info>
struct SegmentTree {
    int n;
    vector<int> tag; // 延迟标记
    vector<Info> info;

    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}

    // 合并子节点信息
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    // 给节点添加延迟标记
    void add(int p, int v, int l, int r) {
        tag[p] += v;
        info[p].sum += (ll)v * (r - l); // 更新区间和
    }

    // 将标记下传到子节点
    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        add(2 * p, tag[p], l, m);
        add(2 * p + 1, tag[p], m, r);
        tag[p] = 0;
    }

    // 查询区间 [x, y)
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) { // 区间不相交
            return {};
        }
        if (l >= x && r <= y) { // 完全覆盖
            return info[p];
        }
        int m = (l + r) / 2;
        push(p, l, r);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }

    // 对外的查询接口
    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    // 区间更新 [x, y): 所有值加上 v
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) { // 区间不相交
            return;
        }
        if (l >= x && r <= y) { // 完全覆盖
            add(p, v, l, r);
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    // 对外的区间更新接口
    void rangeAdd(int x, int y, int v) {
        rangeAdd(1, 0, n, x, y, v);
    }

    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) { // 叶子节点
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }

    // 对外的单点修改接口
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTree<Info> seg(n);

    // 初始化线段树
    for (int i = 0; i < n; ++i) {
        seg.modify(i, {arr[i]});
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) { // 区间加法
            int x, y, k;
            cin >> x >> y >> k;
            --x, --y; // 转为 0-based
            seg.rangeAdd(x, y + 1, k);
        } else if (op == 2) { // 区间求和
            int x, y;
            cin >> x >> y;
            --x, --y; // 转为 0-based
            cout << seg.query(x, y + 1).sum << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1; 

    while (t--) {
        solve();
    }

    return 0;
}
