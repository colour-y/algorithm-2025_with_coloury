#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
struct Fenwick {
    int n;
    vector<int> a;
    Fenwick(int n_) : n(n_), a(n_ + 1) {}
    void add(int x, int v) {
        for (; x <= n; x += x & -x)
            a[x] += v;
    }
    int sum(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x)
            res += a[x];
        return res;
    }
    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};



void solve(){
  int n;
  ll x, y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  for (auto &k : a) cin >> k;
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  ll L = sum - y;
  ll R = sum - x;
  vector<ll> res;
  for (auto k : a) res.push_back(k);
  for (auto k : a) {
      res.push_back(L - k);
      res.push_back(R - k);
  }
  sort(res.begin(), res.end());
 res.erase(unique(res.begin(),res.end()),res.end());
  int m = res.size();
  Fenwick q(m);
  ll ans = 0;
  for (auto k : a) {
      ll x = L - k;
      ll y = R - k;
      int d = lower_bound(res.begin(), res.end(), x) - res.begin();
      int h = lower_bound(res.begin(), res.end(), y) - res.begin();
      int l = d + 1;
      int r = h + 1;
      ans += q.query(l, r);
      int e = lower_bound(res.begin(), res.end(), k) - res.begin();
      q.add(e + 1, 1);
  }
  cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}