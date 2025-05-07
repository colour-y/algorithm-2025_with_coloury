#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()


void solve(){

    int n, q;
    if (!(cin >> n >> q)) return;
    ll g = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        g = (i == 0 ? a : gcd(g, a));
    }

    while (q--) {
        ll v;
        cin >> v;
     
        if (v % g == 0) cout << "Yes";
        else cout << "No";
        cout << nl;
    }
  }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int t = 1;
while(t--){
    solve();
}
    return 0;
}
