#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::string> a(n);
    for(auto &x:a){
        std::cin>>x;
    }
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    std::queue<std::array<int,5>> q;
    q.push({0,0,0,0});
    int vis[n+1][n+1][4][m+1];
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        auto [x,y,f,s,z]=q.front();
        q.pop();
        if(vis[x][y][f][s]){
            continue;
        }
         
        if(x==n-1&&y==n-1){
            std::cout<<z<<endl;
            return ;
        }
        vis[x][y][f][s]=1;
        for(int i=0;i<4;i++){
            if(x+dx[i]<0||x+dx[i]>=n||y+dy[i]<0||y+dy[i]>=n){
                continue;
            }
            if(f==i&&s+1>m){
                continue;
            }
            if(a[x+dx[i]][y+dy[i]]=='*'){
                continue;
            }
            if(f==i){
                q.push({x+dx[i],y+dy[i],f,s+1,z+1});
            }
            else{
                q.push({x+dx[i],y+dy[i],i,1,z+1});
            }
        }
    }
    std::cout<<-1<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}