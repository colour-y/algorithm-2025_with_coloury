#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::map<char,std::map<char,int>> mp;
    for(int i=1;i<=n;i++){
        char x;
        std::vector<char> s;
        while(std::cin>>x){
            s.push_back(x);
        }
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                mp[s[i]][s[j]]=i;
            }
        }
    }
    char s,t;
    std::cin>>s>>t;
    std::cerr<<s<<" "<<t<<endl;
    std::priority_queue<std::tuple<int,int,char>,std::vector<std::tuple<int,int,char>>,std::greater<>> q;
    std::map<char,std::map<int,int>> mp1;
    q.push({2,0,s});
    std::map<char,std::map<int,std::pair<char,int>>> lu;
    while(!q.empty()){
        auto [x,y,z]=q.top();
        q.pop();
        if(mp1[z][y]==1){
            continue;
        }
        if(z==s){
            std::cout<<x<<endl;
            std::vector<char>ans;
            ans.push_back(z);
            std::cerr<<z<<endl;
            while(v!=0){
                ans.push_back(u);
                u=lu[u][v].first;
                v=lu[u][v].second;
            }
            for(int i=ans.size()-1;i>=0;i--){
                std::cout<<ans[i]<<"-\n"[i==0];
            }
            return ;
        }
        mp1[z][y]=1;
        for(auto &[a,b]:mp){
            for(auto &[c,d]:b){
                if(d!=y&&y!=0){
                    if(mp1[d][c]==1){
                        lu[d][c]={z,y};
                        q.push({x+1,d,c});
                    }
                    
                }
                else{
                    if(mp1[d][c]==1){
                        lu[d][c]={z,y};
                        q.push({x,d,c});
                    }
                    
                }
            }
        }
    }
    std::cout<<-1<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}