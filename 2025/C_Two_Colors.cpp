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
ll n,m;
cin >> n >> m ;
vector<int> a(m);
for(auto &e : a){
    cin >> e;
    if(e == n) e--;
}
n--;
ranges::sort(a);
vector<ll> pre(m);
pre[0] = a[0];
for(int i = 1;i < m;i++ ){
    pre[i] = pre[i - 1];
    pre[i] += a[i];
}


ll ans = 0;
for(int i = 0;i < m - 1;i++){
    ll target = n - a[i];
    auto it = upper_bound(a.begin() + i + 1, a.end(), target);
    int cnt = it - a.begin();

    if(it != a.end() ){
        ll k = pre[cnt - 1];
        ans += pre[m - 1] - k;
        
        ans += (ll) 1LL * (m - cnt) * (a[i] - n);
     
    }
}

ans *= 2;
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
