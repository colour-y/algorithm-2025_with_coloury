#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }


    int k = 0;
    for (int x : a) {
        if (x == g) {
            k++;
        }
    }

    if (k > 0) {
        cout << (n - k) << nl;
        return;
    }

 
    int mx = *max_element(a.begin(), a.end());


   
    vector<int> dp(mx + 1, INT_MAX);
    dp[g] = 0;

 
    for (int i = g + 1; i <= mx; i++) {
        int e = INT_MAX;

        for (int j = 0; j < n; j++) {
            int u = gcd(i, a[j]);
            if (u < i) {
                e = min(e, 1 + dp[u]);
            }
        }
        dp[i] = e;
    }

    int mi = INT_MAX;
    for (int x : a) {
        mi = min(mi, dp[x]);
    }
    cout << (mi + (n - 1)) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
