#include <bits/stdc++.h>
using namespace std;

struct Info {
    int count;
    Info() : count(0) {}
    Info(int c) : count(c) {}
    Info operator+(const Info &other) const {
        return Info(count + other.count);
    }
};

template<class Info>
struct SegmentTree {
    int n;
    vector<int> tag;
    vector<Info> info;

    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void add(int p, int v, int len) {
        if (v % 2) {
            info[p].count = len - info[p].count;
            tag[p] ^= v;
        }
    }

    void push(int p, int l, int r) {
        if (tag[p]) {
            int m = (l + r) / 2;
            add(2 * p, tag[p], m - l);
            add(2 * p + 1, tag[p], r - m);
            tag[p] = 0;
        }
    }

    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) return Info();
        if (l >= x && r <= y) return info[p];
        int m = (l + r) / 2;
        push(p, l, r);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }

    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) {
            add(p, v, r - l);
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeAdd(int x, int y, int v) {
        rangeAdd(1, 0, n, x, y, v);
    }
};

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    SegmentTree<Info> seg(N + 1); // 区间为[0, N+1)，对应牛栏1~N

    while (M--) {
        int op, S, E;
        scanf("%d%d%d", &op, &S, &E);
        if (op == 0) {
            seg.rangeAdd(S, E + 1, 1); // 操作区间转换为左闭右开[S, E+1)
        } else {
            Info res = seg.query(S, E + 1);
            printf("%d\n", res.count);
        }
    }

    return 0;
}