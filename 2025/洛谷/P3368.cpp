#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Fenwick Tree or Binary Indexed Tree (BIT) template
template <typename T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    // Initialize the Fenwick Tree with size n_
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{}); // BIT is 1-indexed
    }

    // Add v to the element at index x (1-based index)
    void add(int x, const T &v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }

    // Get the sum from index 1 to x (1-based index)
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }

    // Get the range sum from l to r (1-based index)
    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    
    vector<ll> arr(N + 1);  // The array, 1-indexed
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    // Initialize a Fenwick Tree to handle range updates
    Fenwick<ll> fenwick(N);
    
    // Processing each operation
    while (M--) {
        int op;
        cin >> op;
        if (op == 1) {  // Operation 1: Add k to the range [x, y]
            int x, y, k;
            cin >> x >> y >> k;
            fenwick.add(x, k);  // Add k to index x
            if (y + 1 <= N) {
                fenwick.add(y + 1, -k);  // Subtract k from index y+1
            }
        } else if (op == 2) {  // Operation 2: Query the value at index x
            int x;
            cin >> x;
            cout << arr[x] + fenwick.sum(x) << endl;  // Query the value at index x
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
