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
    vector<ll> now(m);
    for (auto &i : now) cin >> i;
    vector<vector<int>> cs(n, vector<int>(m)), ws(n, vector<int>(m));
    vector<vector<pair<int, int>>> todo(m);
    vector<int> cnt(n);
    queue<int> que;
    for (int i = 0; i < n; i++) {
        auto &c = cs[i], &w = ws[i];
        for (auto &x : c) cin >> x;
        for (auto &x : w) cin >> x;
        for (int j = 0; j < m; j++) {
            if (c[j] > now[j])
                cnt[i]++, todo[j].push_back({c[j], i});
        }
        if (cnt[i] == 0) {
            que.push(i);
        }
    }
    for (int i = 0; i < m; i++)
        sort(todo[i].begin(), todo[i].end());
    vector<int> p(m), len(m);
    for (int i = 0; i < m; i++)
        len[i] = todo[i].size();
    while (que.size()) {
        auto x = que.front();
        que.pop();
        for (int i = 0; i < m; i++) {
            now[i] += ws[x][i];
            while (p[i] < len[i] && now[i] >= todo[i][p[i]].first) {
                cnt[todo[i][p[i]].second]--;
                if (cnt[todo[i][p[i]].second] == 0) {
                    que.push(todo[i][p[i]].second);
                }
                p[i]++;
            }
        }
    }
    if (accumulate(cnt.begin(), cnt.end(), 0LL) == 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
