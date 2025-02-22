#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n,m,s;
cin >> n >> m >> s;
vector<vector<pair<int,int>>> adj(n + 1);
for(int i = 0;i < m;i++){
    int u,v,m;
    cin >> u >> v >> m;
    adj[u].emplace_back(v,m);
}

vector<ll> dist(n + 1,INT_MAX);
dist[s] = 0;
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> pq;
pq.emplace(0,s);
while(!pq.empty()){
    auto [d,u] = pq.top();
    pq.pop();
    if(d > dist[u]) continue;

    for(auto& [v,w] : adj[u]){
        if(dist[v] > dist[u] + w){
            dist[v] = dist[u] + w;
            pq.emplace(dist[v],v);
        }

    }
}
for(int i = 1;i <= n;i++){
    cout << dist[i] << " ";
}
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
