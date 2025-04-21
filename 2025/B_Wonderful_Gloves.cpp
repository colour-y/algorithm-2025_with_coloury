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
ll ans = 0;
vector<int> l(n),r(n),sum(n);
for(auto &e : l){
    cin >> e;
}
for(auto &e : r){
    cin >> e;
}
for(int  i = 0;i < n;i++){
    if(l[i] < r[i]) swap(l[i],r[i]);
}
sort(all(l),greater());
sort(all(r),greater());
ans += reduce(all(l),0LL);
for(int i = 0;i < k - 1;i++){
    ans += r[i];
}
ans++;
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
