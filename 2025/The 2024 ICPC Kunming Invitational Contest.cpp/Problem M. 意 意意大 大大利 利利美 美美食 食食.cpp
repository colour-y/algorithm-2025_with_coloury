#include<bits/stdc++.h>
using namespace std;
#define int long long

using i128 = __int128;
i128 sqr(i128 x) {return x*x;}

struct Pt {
    int x, y;
    int crs(const Pt &b) const {return x*b.y - y*b.x;}
    Pt operator-(const Pt &b) const {return Pt{x-b.x, y-b.y};}
    int len2() const {return x*x + y*y;}
};
int cross(const Pt &p, const Pt &a, const Pt &b) {return (a-p).crs(b-p);}

const int N = 2e5+5;
i128 sum[N];

int solve() {
    int n; cin >> n;
    vector<Pt> pt; pt.resize(2*n+1);
    int x0, y0, r0; cin >> x0 >> y0 >> r0;
    Pt c = Pt{x0, y0};
    for (int i=0; i<n; ++i) {
        int x, y; cin >> x >> y;
        pt[i] = pt[n+i] = Pt{x, y};
    }
    pt[2*n] = pt[0];
    for (int i=1; i<=2*n; ++i) sum[i] = sum[i-1] + pt[i-1].crs(pt[i]);

    auto check = [&](int x, int y) {
        int res = cross(pt[x], pt[y], c);
        return (res > 0) && (sqr(res) >= sqr(r0) * (pt[x]-pt[y]).len2());
    };

    int ans = 0;
    for (int i=0, j=1; i<n; ++i, j=max(j, i+1)) {
        while (j<=2*n && check(i, j)) {
            // printf("i=%lld j=%lld\n", i, j);
            ans = max((i128)ans, sum[j]-sum[i]+pt[j].crs(pt[i]));
            ++j;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while (T--) cout << solve() << '\n';
    return 0;
}

