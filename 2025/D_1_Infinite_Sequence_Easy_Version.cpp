#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  const int N = 2e5 + 5;
  void solve(){
    ll n, l, r, i;
    cin >> n >> l >> r;
    vector<ll> a(n + 2), s(n + 2);
    for (i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0)
    {
        ++n;
        for (i = 1; i <= n / 2; i++) a[n] ^= a[i];
    }
    for (i = 1; i <= n; i++) s[i] = s[i - 1] ^ a[i];
    auto solve = [&](auto &&solve, ll x) -> ll {
        if (x <= n) return a[x];
        x /= 2;
        if (x <= n) return s[x];
        ll r = 0;
        if (x % 2 == 0) r = solve(solve, x), --x;
        r ^= s[n];
        return r;
    };
    cout << solve(solve, l) << '\n';
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
