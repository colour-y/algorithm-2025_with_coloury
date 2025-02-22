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
string s;
cin >> s;

for(int i = 1;i < s.size();i++){
    if(s[i] == s[i - 1]){
        cout << s.substr(0,i) << (s[i] == 'a' ? 'b' : 'a') << s.substr(i) << nl;
        return;
    }
}
s += s.back() == 'a' ? 'b' : 'a';
cout << s << nl;
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
