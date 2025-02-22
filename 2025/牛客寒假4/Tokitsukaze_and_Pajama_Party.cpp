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
string s;
cin >> n >> s;
if(n < 10){
    cout << 0 << nl;
    return;
}
int ans = 0;
int res = 0;
string k = "uwawauwa";
for(int i = 2;i < n - 7;i++){
    if(s[i - 2] == 'u') res++;
if(s.substr(i,8) == k) ans += res;
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
