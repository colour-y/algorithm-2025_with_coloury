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
    map<int,int> mp;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!mp[x]) {
            a.push_back(x);
        }
        mp[x]++;
    }
    sort(all(a));
    int m = a.size();
    vector<int> dp(m, 0);
    dp[0] = 1;  
    for(int i = 1; i < m; i++)
    {
        if (a[i] - a[i-1] > 1) {
            dp[i] = dp[i-1] + 1;
        }
        else {
            int take = 1;
            if (i >= 2) take += dp[i-2];
            dp[i] = max(dp[i-1], take);
        }
    }
    cout << dp[m-1] << nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
