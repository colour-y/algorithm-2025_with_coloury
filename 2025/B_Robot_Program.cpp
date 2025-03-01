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
ll n,x,k;
cin >> n >> x >> k;
string s;
cin >> s;
int p = 0;
int len = 0;
for(int i = 1;i <= n;i++){
    if(s[i - 1] == 'L'){
        p--;
    }else{
        p++;
    }
    if(p == 0){
        len = i;
        break;
    }
}


p = x;
ll ans = 0;
for(int i = 1;i <= n && k ;i++){
    k--;
    if(s[i - 1] == 'L'){
        p--;
    }else{
        p++;
    }
    if(p == 0){
        ans++;
        break;
    }
}
if(ans && len){
    ans += k / len;
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
