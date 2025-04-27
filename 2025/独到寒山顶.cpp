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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, -1));

    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            y--;
            a[i][y] = 1; 
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 0) {
            dist[i][0] = 1;
            q.emplace(i, 0);
        }
    }

    // BFS
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (dist[i][m - 1] != -1) {
            ans = min(ans, dist[i][m - 1]);
        }
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
