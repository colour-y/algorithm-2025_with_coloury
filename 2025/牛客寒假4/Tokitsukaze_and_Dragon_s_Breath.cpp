#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

int dx[4] = {1,1,-1,-1},dy[4] = {-1,1,-1,1};

void solve(){
int n,m;
cin >> n >> m;
vector a(n,vector<ll>(m));
vector<ll> p(n + m) ,q(n + m);
for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
        cin >> a[i][j];
        p[i + j] += a[i][j];
        q[i - j + m] += a[i][j];
    }
}
ll ans = 0;
for(int i = 0 ;i < n;i++){
    for(int j = 0;j < m;j++){
        ans = max(ans, p[i + j] + q[i - j + m] - a[i][j]);
    }
}
cout << ans << nl;
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
