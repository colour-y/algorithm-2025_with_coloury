#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int mi = INT_MAX;
    int ll = 0, rr = 0;
    
    for (int l = 0; l < n; ++l) {
        int res = 0;
        // Check the case when r = l
        if (res < mi) {
            mi = res;
            ll = l;
            rr = l;
        }
        // Process r from l+1 to n-1
        for (int r = l + 1; r < n; ++r) {
            if (a[r] > a[l]) {
                res += 1;
            } else if (a[r] < a[l]) {
                res -= 1;
            }
            // Update if this res is better
            if (res < mi) {
                mi = res;
                ll = l;
                rr = r;
            }
        }
    }
    
    // Convert to 1-based indices
    cout << ll + 1 << " " << rr + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}