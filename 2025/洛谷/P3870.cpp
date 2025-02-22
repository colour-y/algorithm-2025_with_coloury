#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const char nl = '\n';

struct Info
{
    /* data */
    ll sum =  0;
    Info operator+(const Info &other) const{
        return {sum + other.sum};
    }
};


template <class Info>
struct SegmentTree {
    int n;
    vector<int> tag;       // 延迟标记，记录是否需要切换灯状态
    vector<Info> info;     // 存储区间信息

    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}

    // 合并子区间的信息
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    // 切换灯状态并更新当前节点的信息
    void flip(int p, int l, int r) {
        tag[p] ^= 1; // 切换标记（取反）
        info[p].sum = (r - l) - info[p].sum; // 更新区间内亮灯数量
    }

    // 将延迟标记向下传递
    void push(int p, int l, int r) {
        if (tag[p]) {
            int m = (l + r) / 2;
            flip(2 * p, l, m);
            flip(2 * p + 1, m, r);
            tag[p] = 0;
        }
    }

    // 区间切换灯状态 [x, y)
    void rangeFlip(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) return; // 不相交
        if (l >= x && r <= y) { // 完全覆盖
            flip(p, l, r);
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        rangeFlip(2 * p, l, m, x, y);
        rangeFlip(2 * p + 1, m, r, x, y);
        pull(p);
    }

    void rangeFlip(int x, int y) {
        rangeFlip(1, 0, n, x, y);
    }

    // 查询区间 [x, y) 的信息
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) return {}; // 不相交
        if (l >= x && r <= y) return info[p]; // 完全覆盖
        int m = (l + r) / 2;
        push(p, l, r);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }

    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }
};
void solve() {
int n,m;
cin >> n >> m;
SegmentTree<Info> seg(n);

while(m--){
    int c,a,b;
    cin >> c >> a >> b;
    a--,b--;
    if(c == 0){
        seg.rangeFlip(a,b + 1);
    }else{
        cout << seg.query(a,b + 1).sum << nl;
    }
}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1; // 默认单组测试
    // cin >> t; // 如果是多组测试，取消此行注释
    while (t--) {
        solve();
    }

    return 0;
}
