#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
const int N =  1e5 + 5;
 
vector<ll> f[4][N];

void solve(){
int n,m;
cin >> n >> m;
vector a(n,vector<ll>(m)),t(n,vector<ll>(m));
for(int i = 0 ;i < n;i++ ){
    for(int j = 0;j < m;j++){
        cin >> a[i][j];
    }
}
for(int i = 0 ;i < n;i++ ){
    for(int j = 0;j < m;j++){
        cin >> t[i][j];
        f[0][i].resize(m + 1);
        f[1][i].resize(m + 1);
        f[2][i].resize(m + 1);
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
