#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};  
void solve(){
int n,m;
cin >> n >> m;
vector<string> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}

vector vis(n,vector<bool>(m));
vector knn(n,vector<int>(m));
vector kss(n,vector<bool>(m));
auto dfs1 = [&](this auto&& dfs1,int i,int j) -> int{
    int ans = 0;
      vis[i][j] = 1;
for(int k = 0;k < 4;k++){
    int x = dx[k] + i,y = dy[k] + j;
    if(x >= 0 && x < n && y >= 0 && y < m && !knn[x][y] && a[x][y] == '0'){
        knn[x][y] = 1;
        ans++;
        
    }
    else if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && a[x][y] == '1'){
ans += dfs1(x,y);
    }
}
return ans;
};
auto dfs2 = [&](this auto&& dfs2,int i,int j) -> void{
   
      kss[i][j] = 1;
for(int k = 0;k < 4;k++){
    int x = dx[k] + i,y = dy[k] + j;
    if(x >= 0 && x < n && y >= 0 && y < m && knn[x][y] && a[x][y] == '0'){
        knn[x][y] = 0;
        
        
    }
    else if(x >= 0 && x < n && y >= 0 && y < m && !kss[x][y] && a[x][y] == '1'){
 dfs2(x,y);
    }
}
};
int res = INT_MAX;
for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
if(a[i][j] == '1' && !vis[i][j]){

     res = min(res,dfs1(i,j));
     dfs2(i,j);
    }
    }
}
cout << res <<nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
