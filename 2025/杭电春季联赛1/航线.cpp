#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  const int N = 100000;
  const int64 INF = (1LL << 60) - 1;.
  const int dx[4] = {0,-1,0,1};
  const int dy[4] = {1,0,-1,0};

  int t[N + 9],d[N + 9];
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
