#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using d64=double;
using ld64=long double;
#define int long long
static constexpr i64 mod=1000000007;

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<std::pair<int,int>> odd(k+1);
    for(int i=0; i<=k; i++){
        std::cin>>odd[i].first>>odd[i].second;
    }
    int tot=n*m;
    std::vector<std::vector<int>> seg2(k);
    std::vector<std::vector<int>> cell2(tot);
    int bad=0;
    static int dir[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };
    for(int i=0; i<k; i++){
        auto [x1,y1]=odd[i];
        auto [x2,y2]=odd[i+1];
        int d=abs(x1-x2)+abs(y1-y2);
        if(d!=2){
            bad=1;
            break;
        }
        std::vector<int> cand;
        for(int t=0; t<4; t++){
            int nx=x1+dir[t][0],ny=y1+dir[t][1];
            if(nx < 1||nx > n||ny < 1||ny > m){
                continue;
            }
            if(abs(nx-x2)+abs(ny-y2)==1){
                int id=(nx-1)*m+(ny-1);
                cand.push_back(id);
            }
        }
        if(cand.empty()){
            bad=1;
            break;
        }
        seg2[i]=cand;
        for(int c:cand){
            cell2[c].push_back(i);
        }
    }
    if(bad){
        std::cout<<0<<endl;
        return;
    }

    std::vector<int> deg(k);
    for(int i=0; i<k; i++){
        deg[i]=seg2[i].size();

    }
    std::vector<char> used(tot,0),don(k,0);
    std::queue<int> q;
    for(int i=0; i<k; i++){
        if(deg[i]==1){
            q.push(i);
        }
    }

    i64 ans=1;
    while(!q.empty()&&!bad){
        int s=q.front(); q.pop();
        if(don[s]||deg[s]!=1){
            continue;
        }
        int pick=-1;
        for(int c:seg2[s]){
            if(!used[c]){
                pick=c;
                break;
            }
        }
        if(pick<0){
            bad=1;
            break;
        }
        used[pick]=1;
        don[s]=1;
        for(int o:cell2[pick]){
            if(!don[o]){
                deg[o]--;
                if(deg[o]==0){
                    bad=1;
                    break;
                }
                if(deg[o]==1){
                    q.push(o);
                }
            }
        }
    }
    if(bad){
        std::cout<<0<<endl;
        return;
    }

    std::vector<char> vseg(k,0),vcell(tot,0);
    for(int i=0; i<k; i++){
        if(don[i]||vseg[i]){
            continue;
        }
        int cnts=0,cntc=0;
        std::queue<std::pair<int,int>> qq;
        qq.push({ 0,i }); vseg[i]=1;
        while(!qq.empty()){
            auto [ty,u]=qq.front(); qq.pop();
            if(ty==0){
                cnts++;
                for(int c:seg2[u]) if(!used[c]&&!vcell[c]){
                    vcell[c]=1;
                    qq.push({ 1,c });
                }
            }
            else{
                cntc++;
                for(int s2:cell2[u]) if(!don[s2]&&!vseg[s2]){
                    vseg[s2]=1;
                    qq.push({ 0,s2 });
                }
            }
        }
        int cc=cnts-cntc+1;
        if(cc==0){
            ans=ans*cntc%mod;
        }
        else if(cc==1){
            ans=ans*2%mod;
        }
        else{
            ans=0;
        }
        if(ans==0){
            break;
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