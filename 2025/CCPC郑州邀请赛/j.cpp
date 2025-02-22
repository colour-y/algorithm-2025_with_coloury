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
int n = s.size();
map<char,int> mp;
char c;
for(int i = 0;i < n;i++){
if(s[i] == '5' || (s[i] - '0') % 2== 0){
    c = s[i];
}
}
for(int i = 0;i < n;i++){
    if(s[i] != c){
        mp[s[i]]++;
    }
}

for(char k = '9';k >= '0';k--){
  if(mp[k])cout << k;
}
cout << c << nl;
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
