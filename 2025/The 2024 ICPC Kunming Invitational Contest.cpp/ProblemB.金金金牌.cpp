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
int n,k;
cin >> n >> k;
vector<ll> a(n);
ll ans = 0;
for(auto &e : a){
    cin >> e;
    ans += e / k;
    e %= k;
}
ll m;
cin >> m;
sort(all(a),greater());
for(int i = 0;i < n;i++){
    if(m >= k - a[i]){
        m -= k - a[i];
        ans++;
    }else break;
}
ans += m / k;
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
