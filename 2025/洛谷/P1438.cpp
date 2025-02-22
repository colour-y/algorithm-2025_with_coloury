#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()

struct Info {
    ll sum = 0; // 区间和
    Info operator+(const Info &other) const {
        return {sum + other.sum};
    }
};

template <class Info>
struct SegmentTree {
    int n;
    vector<ll> tagAdd, tagDelta; // 懒标记：add为初始增量，delta为等差公差
    vector<Info> info;

    SegmentTree(int n_) : n(n_), tagAdd(4 * n), tagDelta(4 * n), info(4 * n) {}

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void add(int p, int l, int r, ll addValue, ll delta) {
        ll len = r - l;
        info[p].sum += addValue * len + delta * (len * (len - 1)) / 2;
        tagAdd[p] += addValue;
        tagDelta[p] += delta;
    }

    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        if (tagAdd[p] || tagDelta[p]) {
            add(2 * p, l, m, tagAdd[p], tagDelta[p]);
            add(2 * p + 1, m, r, tagAdd[p] + tagDelta[p] * (m - l), tagDelta[p]);
            tagAdd[p] = tagDelta[p] = 0;
        }
    }

    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) return {};
        if (l >= x && r <= y) return info[p];
        int m = (l + r) / 2;
        push(p, l, r);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }

    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    void rangeAdd(int p, int l, int r, int x, int y, ll addValue, ll delta) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) {
            add(p, l, r, addValue, delta);
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        rangeAdd(2 * p, l, m, x, y, addValue, delta);
        rangeAdd(2 * p + 1, m, r, x, y, addValue + delta * max(0, m - max(l, x)), delta);
        pull(p);
    }

    void rangeAdd(int x, int y, ll addValue, ll delta) {
        rangeAdd(1, 0, n, x, y, addValue, delta);
    }

    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
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

    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    SegmentTree<Info> seg(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        seg.modify(i, {a[i]});
    }

    while (m--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            l--, r--;
            seg.rangeAdd(l, r + 1, k, d);
        } else if (opt == 2) {
            int p;
            cin >> p;
            p--;
            cout << seg.query(p, p + 1).sum << nl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
