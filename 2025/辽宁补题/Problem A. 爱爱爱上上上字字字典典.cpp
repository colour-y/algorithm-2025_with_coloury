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
getline(cin,s);
int n;
cin >> n;
map<string,int> mp;
for(int i = 0;i < n;i++){
    string c;
    cin >> c;
    for(auto &e : c){
        if(e >= 'A' && e <= 'Z' ) {
            e -= 'A';
            e += 'a';
        }
    }
    mp[c]++;
   
}
string kt;
int ans = 0;
for(auto c : s){
    if(c >= 'A' && c <= 'Z' ) {
        c -= 'A';
        c += 'a';
    }
if((c >= 'a' && c <= 'z') )kt.push_back(c);
else if(c == ' '){
if(!mp[kt]){
 ans++;
 mp[kt]++;
// cout << kt << nl;
}
kt = "";
}
}

if(!kt.empty() && !mp[kt]) ans++;

cout << ans << nl;
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
