#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

template <class Info>
struct SegmentTree
{
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info())
    {
        init(n_, v_);
    }
    template <class T>
    SegmentTree(vector<T> init_)
    {
        init(init_);
    }
    void init(int n_, Info v_ = Info())
    {
        init(vector(n_, v_));
    }
    template <class T>
    void init(vector<T> init_)
    {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r)
        {
            if (r - l == 1)
            {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p)
    {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m)
        {
            modify(2 * p, l, m, x, v);
        }
        else
        {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v)
    {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
        {
            return Info();
        }
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r)
    {
        return rangeQuery(1, 0, n, l, r);
    }
    template <class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred)
    {
        if (l >= y || r <= x)
        {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p]))
        {
            return -1;
        }
        if (r - l == 1)
        {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1)
        {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findFirst(int l, int r, F &&pred)
    {
        return findFirst(1, 0, n, l, r, pred);
    }
    template <class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred)
    {
        if (l >= y || r <= x)
        {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p]))
        {
            return -1;
        }
        if (r - l == 1)
        {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1)
        {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findLast(int l, int r, F &&pred)
    {
        return findLast(1, 0, n, l, r, pred);
    }
};
constexpr i64 inf = 1E18;
struct Info{
ll sum = 0;
ll ans = -inf;
ll pre = -inf;
ll suf = -inf;
};

Info operator+(const Info &a ,const Info &b){
    Info c;
    c.sum = a.sum + b.sum;
    c.ans = max({a.ans,b.ans,a.suf + b.pre});
c.pre = max(a.pre,a.sum + b.pre);
c.suf = max(a.suf + b.sum,b.suf);
return c;
}

void solve()
{
int n,m;
cin >> n >> m;
vector<vector<pair<int,int>>> modify(n);
for(int i = 0;i < m;i++){
    int l,r,x;
    cin >> l >> r >> x;
    l--;
    modify[l].emplace_back(i,x);
    if(r < n){
        modify[r].emplace_back(i,0);
    }
}

int q;
cin >> q;
vector<ll> ans(q);
vector<vector<array<int,3>>> query(n);
for(int i = 0;i < q;i++){
    int k,s,t;
    cin >> k >> s >> t;
    k--,s--;
    query[k].push_back({i, s, t});
}

SegmentTree<Info> seg(vector(m,Info{0,0,0,0}));

for(int i = 0;i < n;i++){
    for(auto [j,x] : modify[i]){
        seg.modify(j,{x,x,x,x});
    }
    for(auto [j,l,r] : query[i]){
        ans[j] = seg.rangeQuery(l,r).ans;
    }
}
for(int i = 0;i < q;i++){
    cout << ans[i] << nl;
}
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
