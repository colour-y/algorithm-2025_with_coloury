#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve()
{
int n,m;
cin >> n >> m;
vector a(n + 2,vector<int>(m + 2)),vis(n + 2,vector<int>(m + 2));
for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
        char c;
        cin >> c;
        if(c == '.') a[i][j] = 1;
        else a[i][j] = 0;
    }
}
// for(int i = 0;i <= n + 1;i++){
//     for(int j = 0;j <= m + 1;j++){
//         cout << a[i][j];
//     }
//     cout << nl;
// }
vector<array<int,2>> b,c;

if(a[1][1] == 0 && a[n][m] == 0){
    cout << n + m - 1 << nl;
    return;
}


int ok = 0;
auto dfs1 = [&](this auto&& dfs1, auto x,auto y) -> void{
    if(!a[x][y]) return;
 if(vis[x][y]) return;
// if(x > n || y > m) return;
vis[x][y] = 1;
if(a[x][y + 1] == 0 || a[x + 1][y] == 0){
    b.push_back({x,y});
    if(x == n && y == m) ok = 1;
  
}
    if(a[x][y + 1] == 1)
dfs1(x,y + 1);
  if(a[x + 1][y] == 1)
dfs1(x + 1,y);
    if(a[x - 1][y] == 1)
    dfs1(x - 1,y);
    if(a[x][y - 1])
    dfs1(x,y - 1);


};

auto dfs2 = [&](this auto&& dfs2 ,auto x,auto y) -> void{
        if(!a[x][y]) return;
     if(vis[x][y]) return;
// if(x > n || y > m) return;
vis[x][y] = 1;
if(a[x - 1][y] == 0 || a[x][y - 1] == 0){
    c.push_back({x,y});

}
if(a[x][y - 1] == 1)
dfs2(x,y - 1);
if(a[x - 1][y] == 1)
dfs2(x - 1,y);
if(a[x + 1][y] == 1){
    dfs2(x + 1,y);
}
if(a[x][y + 1] == 1) dfs2(x,y + 1);

// cout << x << " " << y << nl;
};

dfs1(1,1);
dfs2(n,m);
if(ok){
    cout << 0 << nl;
    return;
}
int ans = INT_MAX;
b.push_back({1,1});
c.push_back({n,m});
for(auto [x1,y1] : b){
    for(auto [x2,y2] : c){
        ans = min(ans,abs(x1 - x2) + abs(y1 - y2) - 1);
    }
} 

if(a[1][1] == 0 || a[n][m] == 0) ans++;


cout << ans << nl;

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

