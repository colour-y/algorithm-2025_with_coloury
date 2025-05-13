#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
int n,sum[N],maxx,m[N],ans=1,tot;
void solve(){
//解决示例具体方法
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sum[i];
        sum[i]=sum[i]+sum[i-1];
    }
    if(sum[1]<0||sum[n]<0){
        cout<<"-1";
        return;
    }
    maxx=sum[1];
    m[1]=maxx;
    for(int i=2;i<=n;i++){
        if(sum[i]>maxx){
            maxx=sum[i];
        }
        m[i]=maxx;
     //  cout<<i<<' '<<m[i]<<' '<<sum[i]<<endl;
    }
    tot=sum[1];
    for(int i=2;i<=n;i++){
        if(sum[i]+tot>=0){
            ans++;
            tot+=sum[i];
        }else{
            ans++;
            tot+=sum[i];
            if(m[i-1]==0){
                cout<<-1;
                return;
            }
            if(abs(tot)%m[i-1]!=0){
                ans=ans+abs(tot)/m[i-1]+1;
                tot+=(abs(tot)/m[i-1]+1)*m[i-1];
            }else{
                ans=ans+abs(tot)/m[i-1];
                tot+=(abs(tot)/m[i-1])*m[i-1];
            }
        }
    }
    cout<<ans;
}


signed main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
//cin >> t;
while(t--){
    solve();
}
    return 0;
}