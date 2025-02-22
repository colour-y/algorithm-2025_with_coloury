#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

 struct DSU {
    int n;
    std::vector<int> fa, siz;
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
            return false;
        }
        siz[x] += siz[y];
        fa[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

void solve(){
 int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v(m);
    for (auto& [x, y] : v) {
        cin >> x >> y;
    }

    DSU dsu1(n);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        dsu1.merge(x, y);
    }

    int ans = 0;
    DSU dsu2(n);
    for (auto [x, y] : v) {
        if (dsu1.same(x, y)) {
            dsu2.merge(x, y);
        } else {
            ans++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!dsu2.same(i, dsu1.find(i))) {
            ans++;
            dsu2.merge(i, dsu1.find(i));
        }
    }

    cout << ans << "\n";

}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
