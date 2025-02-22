```cpp
struct DSU
{
    vector<int> f, siz;
    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x)
    {
        return siz[find(x)];
    }
};
```

struct DSU {

    int n;

    std::vector`<int>` fa, siz;

    DSU(int n)

    : n(n), fa(n + 1), siz(n + 1, 1) {

    std::iota(fa.begin(), fa.end(), 0);

    }

    int find(int x) {

    if (x != fa[x]) {

    fa[x] = find(fa[x]);

    }

    return fa[x];

    }

    bool same(int x, int y) {

    return find(x) == find(y);

    }

    bool merge(int x, int y) {

    x = find(x);

    y = find(y);

    if (x == y) {

    returnfalse;

    }

    siz[x] += siz[y];

    fa[y] = x;

    returntrue;

    }

    int size(int x) {

    return siz[find(x)];

    }

};

struct DSU {

    int n;

    std::vector`<int>` fa, siz;

    DSU(int n)

    : n(n), fa(n + 1), siz(n + 1, 1) {

    std::iota(fa.begin(), fa.end(), 0);

    }

    int find(int x) {

    if (x != fa[x]) {

    fa[x] = find(fa[x]);

    }

    return fa[x];

    }

    bool same(int x, int y) {

    return find(x) == find(y);

    }

    bool merge(int x, int y) {

    x = find(x);

    y = find(y);

    if (x == y) {

    returnfalse;

    }

    siz[x] += siz[y];

    fa[y] = x;

    returntrue;

    }

    int size(int x) {

    return siz[find(x)];

    }

};
