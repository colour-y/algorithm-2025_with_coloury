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
ll n;
cin >> n;
string s;
cin >> s;
ll ans = 0;
ll k = 0;
bool ok = 0;
ll cc;
for(int i = 0;i < n;i++){
    if(ok == 1){
        ok = 0;
        k = cc;
    }
    if(s[i] == '0'){
        k += 10;
        ans += k;
    }else if(s[i] == '1'){
        k -= 5;
        if(k < 0) k = 0;
        ans += k;
    }else{
        cc = k;
        k -= 10;
        if(k < 0) k = 0;
        ans += k;
        ok = 1;
    }

}
cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
