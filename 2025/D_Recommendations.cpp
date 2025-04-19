#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  template <typename T>
  struct Fenwick
  {
    int n;
    vector<T> a;
    Fenwick(int n_ = 0)
    {
      init(n_);
    }
    void init(int n_)
    {
      n = n_;
      a.assign(n, T{});
    }
    void add(int x, const T &v)
    {
      for (int i = x + 1; i <= n; i += i & -i)
      {
        a[i - 1] = a[i - 1] + v;
      }
    }
    T sum(int x)
    {
      T ans{};
      for (int i = x; i > 0; i -= i & -i)
      {
        ans = ans + a[i - 1];
      }
      return ans;
    }
    T rangeSum(int l, int r)
    {
      return sum(r) - sum(l);
    }
    int select(const T &k)
    {
      int x = 0;
      T cur{};
      for (int i = 1 << __lg(n); i; i /= 2)
      {
        if (x + i <= n && cur + a[x + i - 1] <= k)
        {
          x += i;
          cur = cur + a[x - 1];
        }
      }
      return x;
    }
  };
  
  constexpr int inf = 2e9;

  struct Info{
    int l = 0,r = inf;
  };
  Info operator+(const Info &a ,const Info &b){
return {max(a.l,b.l),min(a.r,b.r)};
  }

void solve(){
int n;
cin >> n;
vector<int> ls(n);
vector<array<int,3>> a(n);
for(int i = 0;auto &[l,r,idx] : a){
    cin >> l >> r;
    idx = i++;
    ls[idx] = l;
}

ranges::sort(a,[](const auto &x ,const auto &y ){
    return x[1] == y[1] ? x[0] < y[0] : x[1] > y[1];
});
ranges::sort(ls);

Fenwick<Info> fen(n + 1);
vector<int> ans(n);


for (int i = 0; i < n; i++) {
    auto [l, r, idx] = a[i];
    int L = ranges::lower_bound(ls, l) - ls.begin();
    if (auto [nl, nr, _] = a[i + 1]; not (i < n - 1 and nr == r and nl == l)) {
        auto res = fen.sum(L + 1);
        if (res.r - res.l < inf) {
            ans[idx] = res.r - res.l - r + l;
        }
    }
    fen.add(L, { l, r });
}
for(int i = 0;i < n;i++){
    cout << ans[i] << nl;
}
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
