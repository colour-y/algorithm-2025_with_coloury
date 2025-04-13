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
vector<ll> a(n),b(n),c(n),pre(n + 1);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
for(auto &e : b){
    cin >> e;
}
for(int i = 0;i < n;i++){
    c[i] = a[i] + b[i];

}

for(int i = 1;i <= n;i++){
    pre[i] = pre[i - 1];
    pre[i] += a[i - 1];
}
ll ans = a[0];
int k = 1;
for(int i = 1;i < n;i++){
if(c[i] == c[i - 1]){
k++;
ans = max(ans,k * (pre[i + 1] - pre[i - k + 1]));

}else {
    k = 1;
    ans = max(ans,k * (pre[i + 1] - pre[i - k + 1]));
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
