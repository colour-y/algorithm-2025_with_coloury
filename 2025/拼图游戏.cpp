#include<bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    set<int> st;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            st.insert(grid[i][j]);
        }
    }

    int result = 0;
    // 枚举所有的 (X, Y)
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            set<int> se;
            for (int i = 0; i < x; ++i) {
                for (int j = 0; j < y; ++j) {
                    se.insert(grid[n - x + i][j]);
                }
            }
            if ((int)se.size() == k) {
                result++;
            }
        }
    }

    cout << result << nl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
