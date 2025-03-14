#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> cnt(31, 0);
    for (int num : a) {
        for (int k = 0; k < 31; ++k) {
            if (num & (1 << k)) {
                cnt[k]++;
            }
        }
    }
    
    int x = 0;
    long long sum = 0;
    for (int k = 0; k < 31; ++k) {
        if (cnt[k] > n - cnt[k]) {
            x |= (1 << k);
        }
        sum += (long long)min(cnt[k], n - cnt[k]) * (1 << k);
    }
    
    cout << x << "\n" << sum << "\n";
    return 0;
}