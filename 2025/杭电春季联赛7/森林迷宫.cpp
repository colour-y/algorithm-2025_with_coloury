#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  #pragma GCC optimize(2)
void solve(){
int n;
cin >> n;
vector e(n + 1,vector<int>());
ll sum = 0;
map<int,map<int,ll>> mp;
for(int i = 0;i < n - 1;i++){
    int u,v,p,q;
    cin >> u >> v >> p >> q;
    e[u].push_back(v);
    e[v].push_back(u);
    mp[u][v] = p;
    mp[v][u] = q;
}

vector<int> par(n + 1,0);
int s,t;
cin >> s >> t;
vector<int> vis(n + 1,0);
auto dfs = [&](auto &&self,int u,int fu) -> void{
    par[u] = fu;
    if(u == t){
        int x = u;
        while(x != 0){
            vis[x] = 1;
            x = par[x];
        }
    }

    for(auto v : e[u]){
        if(v == fu){
            continue;
        }
        self(self,v,u);
    }
};

dfs(dfs,s,0);
ll ans = 0;
auto dfs1 = [&](auto &&self,int u,int fu) -> ll {
    ll sum = 0;
    for(auto v : e[u]){
        if(v == fu){
            continue;
        }
        if(vis[v] == 1){
            sum += mp[u][v] + self(self,v,u);
        }else{
            sum += max(0LL,mp[u][v] + mp[v][u] + self(self,v,u));
        }
    }
    return sum;
};
cout << (dfs1(dfs1,s,0)) << nl;
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
