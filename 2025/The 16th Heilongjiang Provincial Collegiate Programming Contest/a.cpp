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
    vector<int> tag;
    vector<Info> info;
    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}
    void pull(int p)
    {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void add(int p, int v)
    {
        tag[p] += v;
        info[p].max += v;
    }
    void push(int p)
    {
        add(2 * p, tag[p]);
        add(2 * p + 1, tag[p]);
        tag[p] = 0;
    }
    Info query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
        {
            return {};
        }
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    }
    void rangeAdd(int p, int l, int r, int x, int y, int v)
    {
        if (l >= y || r <= x)
        {
            return;
        }

        if (l >= x && r <= y)
        {
            return add(p, v);
        }
        int m = (l + r) / 2;
        push(p);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeAdd(int x, int y, int v)
    {
        rangeAdd(1, 0, n, x, y, v);
    }
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
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
    void modify(int x, const Info &v)
    {
        modify(1, 0, n, x, v);
    }
};

struct Info
{

};

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
    }

   
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
