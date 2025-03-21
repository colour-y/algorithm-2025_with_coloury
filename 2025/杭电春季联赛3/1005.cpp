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
int n;
cin >> n ;
vector<int> a(n);
for(auto &e : a){
    cin >> e;
}

int ans = 0;
vector<vector<int>> adj(n);

for(int i = 0;i < n;i++){
    if(a[i] + i < n && a[i] + i >= 0){
adj[i].push_back(a[i] + i);
adj[a[i] + i].push_back(i);
}

if(i - a[i] >= 0 && i - a[i] < n) {
adj[i].push_back(i - a[i]);
adj[i - a[i]].push_back(i);
}

}


vector<int> memo(n,0);
auto dfs = [&](auto&& self, int k) -> int {  
    if (memo[k]) return 0;
    memo[k] = 1;
    int res = 1;
    for (int v : adj[k]) {  
        res += self(self, v);  
    }
    return res;
};


for(int i = 0;i < n;i++){

int c =  dfs(dfs,i);
if(c) ans++;


}

if(ans == 1) cout << 0 << nl;
else cout << ans - 1 << nl;

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
