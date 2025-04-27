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
int n,m;
cin >> n >> m;
m--;

vector<ll> a(n),b(n);

for(auto &e : a){
    cin >> e;
}
for(auto &e : b){
    cin >> e;
}
a.push_back(0);
b.push_back(0);
ll res = 0;
ll ans = 0;
for(int i = n - 1;i > m;i--){
    res += min(a[i],b[i]);

}
res += a[m];
ans = res;
for(int i = m - 1;i >= 0;i--){
res += a[i];
res -= a[i + 1];
res += min(a[i + 1],b[i + 1]);
ans = min(ans,res);
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
