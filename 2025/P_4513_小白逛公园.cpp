#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
template <class Info, class Merge = std::plus<Info>>
struct SegmentTree
{
    const int n;
    const Merge merge;
    std::vector<Info> info;
    SegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
    SegmentTree(std::vector<Info> init) : SegmentTree(init.size())
    {
        std::function<void(int, int, int)> build = [&](int p, int l, int r)
        { if (r - l == 1)
         { info[p] = init[l]; return; } 
         int m = (l + r) / 2; build(2 * p, l, m); build(2 * p + 1, m, r); pull(p); };
        build(1, 0, n);
    }
    void pull(int p) { info[p] = merge(info[2 * p], info[2 * p + 1]); }
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
    void modify(int p, const Info &v) { modify(1, 0, n, p, v); }
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
        return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
};
struct qujian
{
    int llen, rlen, lmaxn, rmaxn, maxn, len, sum;
    qujian(int x = -INT32_MAX, int y = 0)
    {
        maxn = x;
        llen = y;
        rlen = y;
        lmaxn = x;
        rmaxn = x;
        len = y;
        sum = x;
    }
};
struct merge1
{
    qujian operator()(const qujian &a1, const qujian &a2) const
    {
        if (a1.len == 0)
        {
            return a2;
        }
        if (a2.len == 0)
        {
            return a1;
        }
        qujian ans;
        ans.maxn = max(a1.maxn, a2.maxn);
        ans.len = a1.len + a2.len;
        ans.sum = a1.sum + a2.sum;
        ans.maxn = max(ans.sum, ans.maxn);
        ans.maxn = max(a1.rmaxn + a2.lmaxn, ans.maxn);
        ans.maxn = max(a1.rmaxn + a2.sum, ans.maxn);
        ans.maxn = max(a2.lmaxn + a1.sum, ans.maxn);
        ans.lmaxn = max(a1.lmaxn, a1.sum + a2.lmaxn);
        ans.rmaxn = max(a2.rmaxn, a2.sum + a1.rmaxn);
        return ans;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<qujian> init(n);
    for (int i = 0; i < n; i++)
    {
        cin >> init[i].rmaxn;
        init[i].lmaxn = init[i].maxn = init[i].sum = init[i].rmaxn;
        init[i].len = init[i].llen = init[i].rlen = 1;
    }
    SegmentTree<qujian, merge1> s(init);
    int k, a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> k >> a >> b;
        if (k == 1)
        {
            if (a > b)
            {
                int t = a;
                a = b;
                b = t;
            }
            cout << s.rangeQuery(a - 1, b).maxn << endl;
        }
        else
        {
            s.modify(a - 1, qujian(b, 1));
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}