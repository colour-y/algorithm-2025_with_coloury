#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  int N = 1e5 + 7;
  
void solve(){
int n,m,k;
cin >> n >> m >> k;

vector<ll> f(N,0),g(N,0);
ll res = 0;
for(int i = 0;i < n;i++){
    for(int j = 0;j <= k;j++){
        g[j] = f[j];
    }

    ll a = 0,b = 0;
    for(int j = 0;j < m;j++){
        ll x,y;
        cin >> x >> y;
        a += x;
        b += y;
        for(ll d = 0;d <= k - a;d++) g[d + a] = max(g[d + a],f[d] + b);
    }
    for(int j = 0;j <= k;j++) f[j] = g[j];
    res += b;
 
}

cout << res - f[k] << nl;



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
