#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n,m;
cin >> n >> m ;
vector<ll> a(n);
ll ans = 0;
for(int i = 0;i < n;i++){
    ll sum = 0;
    for(int j = 0;j < m;j++){
        int x ;
        cin >> x;
        ans += 1LL * x * (m - j);
        sum += x;
    }
    a[i] = sum;
}
ranges::sort(a);
for(int i = 0;i < n;i++){
    ans += a[i] * i * m;
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
