#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  
const int N=5*1e5+1;
struct node{
  ll s,w,u,id;
  bool operator <(const node o)const{
    if(s==o.s)return w>o.w;
    return s<o.s;
  }
}f[N];
int x,n,m,k,tot,last,flag,tot1;
void dfs(ll x,ll tt,vector<ll>& v){
    ll xx=x/tt,yy=x%tt;
    for(ll i=1;i<=tt;i++){
        if(yy){
            yy--;
      //      cout<<xx+1<<' ';
            v.push_back(xx+1);
        }else{
        //    cout<<xx<<' ';
            v.push_back(xx);
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    last=-1;flag=0;
    vector<vector<ll>>ans(n+1,vector<ll>(m+1));
    vector<ll>v[n+1];
    for(ll i=1;i<=n;i++){
       cin>>f[i].s;
       f[i].id=i;
       for(ll j=1;j<=m;j++){
          cin>>ans[i][j];
          if(ans[i][j]==-1){
            f[i].u++;
          }else{
            f[i].w+=ans[i][j];
          }
       }
    }
    sort(f+1,f+n+1);
    for(ll i=1;i<=n;i++){
        if(last==-1){
            last=f[i].s;
            tot=f[i].w;
            tot1=0;
            for(ll i=1;i<=f[i].u;i++){
                v[i].push_back(0);
            }
            continue;
        }
        if(f[i].s!=last){
            last=f[i].s;
            if(f[i].w<=tot){
                tot1=tot;
                tot=tot+1;
                ll cnt=tot-f[i].w;           
                  if(cnt>k*f[i].u){
                    flag=1;
                    break;
                  }else{
                     dfs(cnt,f[i].u,v[i]);
                  //   cout<<endl;

                  }
            }else{
                tot1=tot;
                tot=f[i].w;
                for(ll i=1;i<=f[i].u;i++){
                    v[i].push_back(0);
                }
            }
        }else{
            if(tot1-f[i].w>f[i].u*k){
                flag=1;
                break;
            }else{
                dfs(tot-f[i].w,f[i].u,v[i]);
            }
        }
    }
    if(flag){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        for(ll i=1;i<=n;i++){
            ll cnt=0;
            for(ll j=1;j<=m;j++){
                if(ans[i][j]==-1){
                    ans[i][j]=v[f[i].id][cnt];
                    cnt++;
                    cout<<1<<' ';
                }
                cout<<endl;
            }
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cout<<ans[i][j]<<' ';
            }
            cout<<endl;
        }
    }
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
