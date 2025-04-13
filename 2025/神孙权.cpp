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
ll x;
cin >> n >> x;
ll m = 0;
while(m <= x){
    x -= m;
    x++;
    m++;
}

if(m >= n) m = n;
vector<ll> a(n);
for(auto &e : a){
    cin >> e;

}
vector <ll> s1(n + 1),s2(n + 1),mx(n + 1);
for(int i = 0;i < n;i++) s1[i + 1] = s1[i] + a[i];
for(int i = 0;i < n;i++) s2[i + 1] = s2[i] + a[n - i - 1];
mx[0] = s2[0];
for(int i = 1;i <= n;i++) mx[i] = max(mx[i - 1] ,s2[i]);
ll ans = 0;
for(int i = 0;i <= m;i++) ans = max(ans,s1[i] + mx[m - i]);
cout << ans << nl;

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
