#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

vector<vector<int>> adj;
vector<bool> removed, in_comp, seen;
vector<tuple<ll,int,int>> ans;


pair<int,int> bfs_farthest(int src, vector<int>& comp, bool record_parent, vector<int>& parent, vector<int>& dist) {
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    if (record_parent) parent[src] = -1;
    int best_d = 0, best_node = src;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int du = dist[u];
        if (du > best_d || (du == best_d && u > best_node)) {
            best_d = du;
            best_node = u;
        }
        for (int v : adj[u]) {
            if (!removed[v] && in_comp[v] && dist[v] == -1) {
                dist[v] = du + 1;
                if (record_parent) parent[v] = u;
                q.push(v);
            }
        }
    }
    return {best_node, best_d};
}

void solve_comp(vector<int>& comp) {
    if (comp.empty()) return;
    for (int u : comp) {
        in_comp[u] = true;
        seen[u] = false;
    }
    int s = comp[0];
    int N = comp.size();
    vector<int> dist(N+5, -1), parent(N+5, -1);
    auto [A, _d1] = bfs_farthest(s, comp, false, parent, dist);
    for (int u : comp) dist[u] = -1;
    auto [B, d2] = bfs_farthest(A, comp, true, parent, dist);

    ll d = (ll)d2 + 1;
    int u = max(A, B), v = min(A, B);
    ans.emplace_back(d, u, v);
    int cur = B;
    while (cur != -1) {
        removed[cur] = true;
        cur = parent[cur];
    }
    for (int x : comp) in_comp[x] = false;
    vector<int> tmp;
    for (int x : comp) {
        if (!removed[x] && !seen[x]) {
            tmp.clear();
            queue<int> q;
            q.push(x);
            seen[x] = true;
            while (!q.empty()) {
                int y = q.front(); q.pop();
                tmp.push_back(y);
                for (int w : adj[y]) {
                    if (!removed[w] && !seen[w]) {
                        seen[w] = true;
                        q.push(w);
                    }
                }
            }
            solve_comp(tmp);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    adj.assign(n+1, {});
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    removed.assign(n+1, false);
    in_comp.assign(n+1, false);
    seen.assign(n+1, false);
    ans.clear();
    vector<int> all(n);
    iota(all.begin(), all.end(), 1);
    solve_comp(all);

    vector<ll> ans;
    ans.reserve(ans.size()*3);
    for (auto &t : ans) {
        ll d; int u, v;
        tie(d,u,v) = t;
        ans.push_back(d);
        ans.push_back(u);
        ans.push_back(v);
    }

    for (ll x : ans) {
        cans << x << ' ';
    }
    cans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
