#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()


  int foo(vector<vector<int>> v,vector<int> a) {
    int n=v.size();

    vector<vector<int>> rel(n-1,vector<int>(4,1)); // 00 11 01 10

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n;j++) {
            int p=v[i][j],q=v[i+1][j];
            if(p==q) rel[i][0]=rel[i][1]=0;
            else if(p==q-1) rel[i][3]=0;
            else if(p==q+1) rel[i][2]=0;
        }
    }

    vector<int> dp0(n,1e18),dp1(n,1e18);

    dp0[0]=0;
    dp1[0]=a[0];

    for(int i=1;i<n;i++) {
        if(rel[i-1][0]) {
            dp0[i]=min(dp0[i],dp0[i-1]);
        }
        if(rel[i-1][1]) {
            dp1[i]=min(dp1[i],dp1[i-1]+a[i]);
        }
        if(rel[i-1][2]) {
            dp1[i]=min(dp1[i],dp0[i-1]+a[i]);
        }
        if(rel[i-1][3]) {
            dp0[i]=min(dp0[i],dp1[i-1]);
        }
    }

    return min(dp0[n-1],dp1[n-1]);
}

void solve() {

    int n;cin>>n;

    vector<vector<int>> v(n,vector<int>(n)),w(n,vector<int>(n));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int x;cin>>x;
            v[i][j]=x;
            w[j][i]=x;
        }
    }

    vector<int> a(n),b(n);
    for(auto &e:a) cin>>e;
    for(auto &e:b) cin>>e;

    int ans=0;
    ans+=foo(v,a);
    ans+=foo(w,b);

    if(ans<1e18) {
        cout<<ans<<endl;
    } else {
        cout<<-1<<endl;
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
