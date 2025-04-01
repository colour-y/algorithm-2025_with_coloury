#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
    int sum, lmax, rmax, tmax;
    Info() : sum(0), lmax(-1e9), rmax(-1e9), tmax(-1e9) {}
    Info(int val) : sum(val), lmax(val), rmax(val), tmax(val) {}
    Info operator+(const Info& rhs) const {
        Info res;
        res.sum = sum + rhs.sum;
        res.lmax = max(lmax, sum + rhs.lmax);
        res.rmax = max(rhs.rmax, rhs.sum + rmax);
        res.tmax = max({tmax, rhs.tmax, rmax + rhs.lmax});
        return res;
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
    
    void add(int p, int v) {
        tag[p] += v;
        info[p].sum += v;
        info[p].lmax += v;
        info[p].rmax += v;
        info[p].tmax += v;
    }
    
    void push(int p) {
        if (tag[p]) {
            add(2 * p, tag[p]);
            add(2 * p + 1, tag[p]);
            tag[p] = 0;
        }
    }
    
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) return Info();
        if (l >= x && r <= y) return info[p];
        int m = (l + r) / 2;
        push(p);
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
        int m = (l + r) / 2;
        push(p);
        if (x < m) modify(2 * p, l, m, x, v);
        else modify(2 * p + 1, m, r, x, v);
        pull(p);
    }
    
    void modify(int x, const Info& v) {
        modify(1, 0, n, x, v);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    SegmentTree<Info> seg(n);
    for (int i = 0; i < n; ++i) {
        seg.modify(i, Info(arr[i]));
    }
    
    while (m--) {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 1) {
            if (a > b) swap(a, b);
            int l = a - 1, r = b;
            Info res = seg.query(l, r);
            cout << res.tmax << '\n';
        } else {
            int p = a - 1;
            seg.modify(p, Info(b));
        }
    }
    
    return 0;
}