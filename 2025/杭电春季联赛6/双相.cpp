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
vector<ll> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
string s;
cin >> s;
vector<ll> b,c;
for(int i = 0;i < n;i++){
    if(s[i] == 'R') b.push_back(a[i]);
    else c.push_back(a[i]);
}

sort(all(b),greater());
sort(all(c),greater());
ll ans = 0;
int i;
for(i = 0;i < b.size() && i < c.size();i++){
ans += b[i];
ans += c[i];
}

if(c.size() < b.size()) ans += b[i];
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
