#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
ll n;
cin >> n;
vector<vector<int>> adj(n);
for(int i = 1;i < n;i++){
    int x,y;
    cin >> x >> y;
    x--,y--;
    adj[x].push_back(y);
    adj[y].push_back(x);

}
vector<ll> ans(n),siz(n);
auto dfs = [&](auto self, int u, int pre) -> void {
    siz[u] = 1;
    for (auto v : adj[u]) {
        if (v == pre)
            continue;
        self(self, v, u);
        siz[u] += siz[v];
    }
};

dfs(dfs,0,-1);

auto getans = [&](auto self, int u, int pre) -> void {
    for (auto v : adj[u]) {
        if (v == pre)
            continue;
        self(self, v, u);
    }
    ll sum2 = 0, sum3 = 0;
    for (auto v : adj[u]) {
        if (v == pre)
            sum2 += (n - siz[u]) * (n - siz[u]), sum3 += (n - siz[u]) * (n - siz[u]) * (n - siz[u]);
        else
            sum2 += siz[v] * siz[v], sum3 += siz[v] * siz[v] * siz[v];
    }

    ans[u] = n + ((n - 1) * (n * n - n - sum2) + sum2 * (-2 * n + 1) + sum3 * 2) / 2 + (n - 1) * n - sum2;
};
getans(getans,0,-1);
for(auto i : ans){
    cout << i << " ";
}
cout << nl;
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
