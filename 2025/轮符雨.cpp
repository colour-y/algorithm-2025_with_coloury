#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n;
cin >> n;
vector<ll> a(n);
ll mx = 0,mi = INT_MAX;
for(auto &e : a){
    cin >> e;
    mx = max(mx,e);
    mi = min(mi,e);
}
ll ans = abs(a[0] - a[n - 1]);

ans = max(mx - a[n - 1],ans);
ans = max(a[0] - mi,ans);`

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
