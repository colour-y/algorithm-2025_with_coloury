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
cin >> n;
string s;
cin >> s;
int pre = 0;
ll ans = 0;
for(int i = 0;i < n;i += 2)
{
        if(pre > 0){
        pre--;
    }else{
        pre++;
    }
    ans += pre;
    pre += (s[i + 1] == '(' ? 1 : -1);
    ans += pre;
}
cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
