#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
const char f[]={'a','b'};
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
int n,a[2*N+2],tot,flag;
vector<char>ans(2*N+3,'-');
void solve(){
    cin>>n;
    for(int i=1;i<=2*n+2;i++){
        cin>>a[i];
        if(i%2==0){
            ans[i]='#';
        }
    }
    flag=0;
    tot=2*n+2;
    for(int i=2*n+2;i>=2;i--){
        if(i-a[i]+1<=tot){
            for(int j=i-a[i]+1,k=i+a[i]-1;j<=min(i,tot);j++,k--){
                if(ans[k]=='-'){
                    ans[k]=f[flag];
                    ans[j]=ans[k];
                    flag=1-flag;
                }else{
                    ans[j]=ans[k];
                }
            }
            tot=min(tot,i-a[i]+1);
        }
    }
    for(int i=3;i<=2*n+2;i+=2){
        cout<<ans[i];
    }
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