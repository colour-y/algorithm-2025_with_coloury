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
int n;
cin >> n ;
vector<pair<ll,ll>> a(n);
for(int i = 0 ;i < n;i++){
    cin >> a[i].first;
}
for(int i = 0;i < n;i++){
    cin >> a[i].second;

}

auto check = [&](ll k){
   ll lk = a[0].first - k * a[0].second,rk = a[0].first + k * a[0].second;
for(int i = 1;i < n;i++){
    ll tl = a[i].first - k * a[i].second,tr = a[i].first + k * a[i].second;
    if(tl > lk) lk = tl;
    if(tr < rk) rk = tr;
    if(lk > rk) return false;
}
return true;
};
ll l = 0,r = 1e10;
while(l < r){
ll mid = (l + r) / 2;
if(check(mid)) r = mid;
else l = mid + 1;
}

cout << l << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
