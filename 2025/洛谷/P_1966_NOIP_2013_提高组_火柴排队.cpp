#include<bits/stdc++.h>
using namespace std;

const int MOD = 99999997;

struct Fenwick {
    vector<int> tree;
    int n;
    Fenwick(int size) : n(size), tree(size + 1, 0) {}
    
    void update(int pos) {
        pos++;
        while (pos <= n) {
            tree[pos]++;
            pos += pos & -pos;
        }
    }
    
    int query(int pos) {
        pos++;
        int res = 0;
        while (pos > 0) {
            res += tree[pos];
            pos -= pos & -pos;
        }
        return res;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        a[i] = {val, i};  // (值, 原下标)
    }
    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        b[i] = {val, i};
    }
    
    // 对a和b按值排序，得到排名映射
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // 构建映射数组x: b的每个元素对应的a的原始下标
    vector<int> x(n);
    for (int i = 0; i < n; ++i) 
        x[b[i].second] = a[i].second;
    
    // 树状数组计算逆序对
    Fenwick ft(n);
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += ft.query(x[i] - 1);  // 查询比x[i]小的数数量
        ft.update(x[i]);
    }
    
    printf("%lld\n", ans % MOD);
    return 0;
}