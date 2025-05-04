#include <bits/stdc++.h>
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
    vector<ll> a(n);
    map<ll,int> mp;
    int ans = 1;
    for (auto &e : a)
    {
        cin >> e;
        mp[e]++;
ans = max(ans,mp[e]);
    }
    ranges::sort(a);
   
    for (int _ = 1; _ < n - 1; _++)
    {
        ll mid = a[_];
   
        int l = 0;
        while (l < _ )
        {
            int r = lower_bound(all(a), 2 * mid - a[l]) - a.begin();
            if(r == n){
                l++;
                continue;
            }
            while(r < n - 1){
                if(a[r + 1] == a[r]){
                    r++;
                }else break;
            }
            // cout << a[l] << " " << a[r] << " " << mid << nl;
            // cout << l << " " << r << " " << _ << nl << nl;
          
               if((a[l] + a[r]) == mid * 2 &&  _ == (l + r) / 2){
                    ans = max(ans,r - l + 1);
                    break;
                }else{
                    if((a[l] + a[r]) == mid * 2){
if(r - _ > _ - l) ans = max(ans,(_ - l) * 2 + 1);
else ans = max(ans,(r - _) * 2 + 1);

}
                    l++;
                }   
               
               
        }
        // cout << mid << nl;
    }
    cout << ans << nl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
