#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const char nl = '\n';

struct Info {
    ll sum = 0;
    Info operator+(const Info& other) const {
        return {sum + other.sum};
    }
};

template<class Info>
struct SegmentTree {
    int n;
    vector<ll> tag;
    vector<Info> info;
    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void apply(int p, ll v, int len) {
        tag[p] += v;
        info[p].sum += v * len;
    }

    void push(int p, int l, int r) {
        if (tag[p]) {
            int m = (l + r) / 2;
            apply(2 * p, tag[p], m - l);
            apply(2 * p + 1, tag[p], r - m);
            tag[p] = 0;
        }
    }

    void rangeAdd(int p, int l, int r, int x, int y, ll v) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) {
            apply(p, v, r - l);
            return;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeAdd(int x, int y, ll v) {
        rangeAdd(1, 0, n, x, y, v);
    }

    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) return Info();
        if (l >= x && r <= y) return info[p];
        push(p, l, r);
        int m = (l + r) / 2;
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }

    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        if (x < m) modify(2 * p, l, m, x, v);
        else modify(2 * p + 1, m, r, x, v);
        pull(p);
    }

    void modify(int x, const Info& v) {
        modify(1, 0, n, x, v);
    }
};

void solve() {
    int n, f;
    cin >> n >> f;
    SegmentTree<Info> st(n + 2); // 1-based处理

    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        st.modify(i, {x});
    }

    while (f--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            st.rangeAdd(l, r + 1, k); // [l, r] -> [l, r+1)
        } else if (op == 2 || op == 3) {
            int k;
            cin >> k;
            if (op == 3) k = -k;
            st.rangeAdd(1, 2, k); // 主墓碑在位置1
        } else if (op == 4) {
            int l, r;
            cin >> l >> r;
            auto res = st.query(l, r + 1);
            cout << res.sum << nl;
        } else if (op == 5) {
            auto res = st.query(1, 2);
            cout << res.sum << nl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}