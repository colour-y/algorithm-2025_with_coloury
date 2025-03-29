#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> dp(k, 0);
    
    for (int j = 0; j < k; ++j) {
        dp[j] = a[0][j];
    }

    for (int i = 1; i < n; ++i) {
        vector<int> b(k, 0);
        int mx = dp[0];
        b[0] = mx + a[i][0];
        for (int j = 1; j < k; ++j) {
            mx = max(mx, dp[j]);
            b[j] = mx + a[i][j];
        }
        dp = move(b);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
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