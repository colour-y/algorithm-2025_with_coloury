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
string s;
cin >> s;
ll x = 0,y = 0;
for(int i =0 ;i < n;i++){
if(s[i] == '-')x++;
else y++;
}

if(x < 2){
    cout << 0  << nl;
    return;
}

if(x % 2){
    ll ans = y * (x/ 2) * (x / 2 + 1);

    cout << ans << nl;
}else{
    ll ans = y * (x / 2) * (x / 2);
    cout << ans  << nl;
}
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
