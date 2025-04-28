#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector a(n,std::vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>a[i][j];
            a[i][j]--;
        }
    }
    std::vector b(n,std::vector<std::bitset<2000>>(m));
    b[0][0].set(a[0][0]);
    int ans=0;
    if(b[0][0].count()==k){
        ans++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=0){
                b[i][j]|=b[i-1][j];
            }
            if(j!=0){
                b[i][j]|=b[i][j-1];
            }
            b[i][j].set(a[i][j]);
            if(b[i][j].count()==k){
                ans++;
            }
        }
    }
    std::cout<<ans<<endl;
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