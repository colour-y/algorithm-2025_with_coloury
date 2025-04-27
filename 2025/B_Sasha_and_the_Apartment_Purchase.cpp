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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

 
    vector<pair<ll,ll>> q;


    int mx = min(k, n - 2);
    for (int c = 0; c <= mx; c++) {
        int m = n - c;
        int x = (m - 1) / 2;    
        int y = (n - m) + (m / 2);
        q.emplace_back(a[x], a[y]);
    }


    if (k == n - 1) {
        for (ll x : a) {
            q.emplace_back(x, x);
        }
    }

  
    sort(q.begin(), q.end());
    ll ans = 0;
    ll l = q[0].first;
    ll r = q[0].second;
    for (int i = 1; i < q.size(); i++) {
        ll L = q[i].first;
        ll R = q[i].second;
        if (L > r) {
            
            ans += (r - l + 1);
            l = L;
            r = R;
        } else {
            
            r = max(r, R);
        }
    }

    ans += (r - l + 1);

    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
       solve();
    }

    return 0;
}
