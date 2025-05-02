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
vector<ll> a;
for(int i = 0;i < n;i++)
{
    ll x;
    cin >> x;
    if(a.empty()) a.push_back(x);
    else if(a.back() != x) a.push_back(x);
}
n = a.size();
int ans = 0;
for(int i = 1;i < n - 1;i++){
    if(a[i - 1] < a[i] && a[i + 1] < a[i]) ans++;
}
if(n == 1){
    cout << 1 << nl;
    return;
}
if(a[0] > a[1]) ans++;
if(a[n - 1] > a[n - 2]) ans++;
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
