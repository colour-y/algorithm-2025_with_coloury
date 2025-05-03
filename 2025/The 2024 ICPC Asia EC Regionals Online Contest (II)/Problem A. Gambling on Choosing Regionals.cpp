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
//解决示例具体方法
int n,k;
cin >> n >> k;
vector<ll> b(k);
for(auto &e : b){
  cin >> e;
}
sort(all(b));
map<string,int> mp;
vector<pair<ll,string>> a(n);
map<string,vector<ll>> np;
for(int i = 0;i < n;i++){
  cin >> a[i].first >> a[i].second;
  np[a[i].second].push_back(a[i].first);
}
for(auto [x,y] : np){
  ranges::sort(y);
}
ll q = b[0];
vector<ll> ans(n,1);
for(int i = 0;i < n;i++){
for(auto [x,y] : np){
  ll m = y.size();
  ll e = upper_bound(all(y),a[i].first) - y.begin();
ll res = 0;
if(e == 0) res = min(m,q);
else if(e == m) continue;
e = m - e + 1;
if(x == a[i].second){
  res = min(e,q - 1);
}else
res = min(e,q);
// cout << res << nl;
ans[i] += res;
// cout << e << " " << m << nl;

//   if(x == a[i].second) e = min(b[0],e - 1);
//   else 
// e = min(b[0],e);
//   if(e != m)
//   ans[i] += m - e + 1;
} 
// cout << nl;
cout << ans[i] << nl;
}



// for(int i = 0;i < n;i++){
//   cout << ans[i] << nl;
// }
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}
