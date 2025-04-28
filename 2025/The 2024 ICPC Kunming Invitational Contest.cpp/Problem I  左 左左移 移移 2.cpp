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
string s;
cin >> s;
int n = s.size();
if(count(all(s),s[0]) == n){
    cout << n / 2 << nl;
    return;
}
s += s;
int ans = 0,res = 0;

vector<int> a(2 * n,1),suf(2 * n,1);
for(int i = 1;i  < 2 * n;i++){
if(s[i] == s[i - 1]){
    a[i] = a[i - 1] + 1;
}
}

for(int i = 2 * n - 2;i >= 0;i--){
    if(s[i] == s[i + 1]){
        suf[i] = suf[i + 1] + 1; 
    }
}

for(int i = 0;i < n;i++){
    if(s[i] != s[i + 1]){
        if(a[i] != 1) res += a[i] / 2;

    } 
}
if(s[n - 1] == s[n]) res += a[n - 1] / 2;

ans = res;
for(int i = 1;i < n;i++){
    int j = i + n - 1;

    if(s[i - 1] == s[i]){
    res -= suf[i - 1] / 2;
    res += suf[i] / 2;
}

if(s[j - 1] == s[j]){
    res -= a[j - 1] / 2;
    res += a[j] / 2;
}
    ans = min(ans,res); 
    // cout << suf[i - 1] << " " << suf[i] << " " << a[j - 1] << " " << a[j] << nl;
//   cout << res << nl;
}
// cout << s << nl;
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
