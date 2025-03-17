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
for(auto &e : a){
    cin >> e;
}
ll ans = 0;
if(k == 1){
vector<ll> b(n - 2);
for(int i = 1;i < n - 1;i++){
    b[i - 1] = a[i];
}

ans = max(a[0],a[n - 1]);
b.push_back(min(a[0],a[n - 1]));
sort(all(b),greater());
for(int i = 0;i < k ;i++)
{
    ans += b[i];
}
}
else{
    ranges::sort(all(a),greater());
    for(int i = 0;i <= k;i++){
        ans += a[i];
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
