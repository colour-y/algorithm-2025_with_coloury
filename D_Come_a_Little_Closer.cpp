#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    vector<array<ll,2>> a(n);
  
    map<ll,int> mp, np;

    ll mix1 = LLONG_MAX, mix2 = LLONG_MAX;
    ll mxx1 = LLONG_MIN, mxx2 = LLONG_MIN;
    int cmix1 = 0, cmxx1 = 0;

    ll miy1 = LLONG_MAX, miy2 = LLONG_MAX;
    ll mxy1 = LLONG_MIN, mxy2 = LLONG_MIN;
    int cmiy1 = 0, cmxy1 = 0;

 
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        ll x = a[i][0], y = a[i][1];
 
        mp[x]++;
        np[y]++;

        if (x < mix1) {
            mix2 = mix1; mix1 = x;
        } else if (x > mix1 && x < mix2) {
            mix2 = x;
        }

        if (x > mxx1) {
            mxx2 = mxx1; mxx1 = x;
        } else if (x < mxx1 && x > mxx2) {
            mxx2 = x;
        }
 
        if (y < miy1) {
            miy2 = miy1; miy1 = y;
        } else if (y > miy1 && y < miy2) {
            miy2 = y;
        }

        if (y > mxy1) {
            mxy2 = mxy1; mxy1 = y;
        } else if (y < mxy1 && y > mxy2) {
            mxy2 = y;
        }
    }

        if (n == 1) {
        cout << 1 << nl;
        return;
    }

    cmix1 = mp[mix1];
    cmxx1 = mp[mxx1];
    cmiy1 = np[miy1];
    cmxy1 = np[mxy1];
    if (mix2 == LLONG_MAX) mix2 = mix1;
    if (miy2 == LLONG_MAX) miy2 = miy1;
    if (mxx2 == LLONG_MIN) mxx2 = mxx1;
    if (mxy2 == LLONG_MIN) mxy2 = mxy1;


    auto area = [&](ll x1, ll x2, ll y1, ll y2) {
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    };


    ll ans = area(mix1, mxx1, miy1, mxy1);


    for (int i = 0; i < n; i++) {
        ll x = a[i][0], y = a[i][1];

        ll x1 = (x == mix1 && cmix1 == 1 ? mix2 : mix1);
        ll x2 = (x == mxx1 && cmxx1 == 1 ? mxx2 : mxx1);
        ll y1 = (y == miy1 && cmiy1 == 1 ? miy2 : miy1);
        ll y2 = (y == mxy1 && cmxy1 == 1 ? mxy2 : mxy1);

        ll l = x2 - x1 + 1;
        ll h = y2 - y1 + 1;
        ll e = l * h;
        ll res;

        if (e > n - 1) {
            res = e;
        } else {
            res = min((l + 1) * h, l * (h + 1));
        }
        ans = min(ans, res);
    }

    cout << ans << nl;
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
