#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

bool checkSimplePath(int n, const vector<vector<int>>& tree) {
    for (int i = 1; i <= n; ++i) {
        if (tree[i].size() > 2) {
            return false; // 如果有度大于2的节点，无法找到简单路径
        }
    }
    return true;
}

void solve(){
        int n;
        cin >> n;

        vector<vector<int>> tree(n + 1);
        vector<int> degree(n + 1, 0);

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // 先检查是否存在度数大于2的节点
        if (!checkSimplePath(n, tree)) {
            cout << -1 << endl;
            return;
        }

        // 找到一个叶子节点
        int start = 1;
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 1) {
                start = i;
                break;
            }
        }

        // 进行BFS或DFS找树的直径
        queue<int> q;
        vector<int> dist(n + 1, -1);
        dist[start] = 0;
        q.push(start);

        int farthest_node = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : tree[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    farthest_node = neighbor;
                }
            }
        }

        // 从最远节点再进行BFS找到树的另一个端点
        dist.assign(n + 1, -1);
        dist[farthest_node] = 0;
        q.push(farthest_node);

        int end = farthest_node;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : tree[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    end = neighbor;
                }
            }
        }

        // 输出结果，树的直径两个端点
        cout << farthest_node << " " << end << endl;
    }



int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
