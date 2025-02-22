#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8 - 3;

// Fenwick Tree / Binary Indexed Tree (BIT)
class FenwickTree {
public:
    FenwickTree(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        for (int i = idx; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }

    int query(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }

private:
    int n;
    vector<int> bit;
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // Step 1: Coordinate compression for a and b
    vector<int> all = a;
    all.insert(all.end(), b.begin(), b.end());
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    // Create a mapping from original value to compressed index
    auto compress = [&](int x) {
        return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
    };

    // Compress both arrays a and b
    for (int i = 0; i < n; i++) {
        a[i] = compress(a[i]);
        b[i] = compress(b[i]);
    }

    // Step 2: Count the minimum number of swaps to align a and b

    // We need to find the relative positions of the elements in b
    vector<int> position_in_b(n);
    for (int i = 0; i < n; i++) {
        position_in_b[b[i] - 1] = i;
    }

    // Step 3: Calculate the number of inversions using Fenwick Tree
    FenwickTree fenwick(n);
    long long swaps = 0;

    // Traverse through array `a` and calculate the inversions using Fenwick Tree
    for (int i = 0; i < n; i++) {
        // We need to count how many numbers in the Fenwick Tree are larger than the current number's target position
        swaps += fenwick.query(n) - fenwick.query(position_in_b[a[i] - 1]);
        // Now update the Fenwick Tree with the current position
        fenwick.update(position_in_b[a[i] - 1] + 1, 1);
    }

    // Step 4: Output the result
    cout << swaps % MOD << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
