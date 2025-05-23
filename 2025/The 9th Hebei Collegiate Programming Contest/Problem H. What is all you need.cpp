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
if(s.size() < 12){
    cout << "No" << nl;
    return;
}
string ans;
for(int i = 0;i < s.size();i++){
    if(s.substr(i) == "isallyouneed"){
        cout << "Yes" << nl;
        cout << ans << nl;
        return;
    }
    ans += s[i];
}
cout << "No" << nl;
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
