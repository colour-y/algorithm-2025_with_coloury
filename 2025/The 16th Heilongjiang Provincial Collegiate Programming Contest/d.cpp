#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
const int mod=1000003;
long long n,f[301][301],a[301],g[301][301];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        g[i][i]=i;
    }
    for(int len=1;len<n;len++){
        for(int i=1;i<=n-len;i++){
            int j=i+len;
            if(f[i][j]<f[i+1][j]+(a[i]-g[i+1][j])*(a[i]-g[i+1][j])){
                f[i][j]=f[i+1][j]+(a[i]-g[i+1][j])*(a[i]-g[i+1][j]);
                g[i][j]=(a[i]*g[i+1][j])%mod;
            }
            if(f[i][j]<f[i][j-1]+(a[j]-g[i][j-1])*(a[j]-g[i][j-1])){
                f[i][j]=f[i+1][j]+(a[j]-g[i][j-1])*(a[j]-g[i][j-1]);
                g[i][j]=(a[j]*g[i][j-1])%mod;
            }
        }
    }
    cout<<f[1][n];
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
//cin >> t;
while(t--){
    solve();
}
    return 0;
}