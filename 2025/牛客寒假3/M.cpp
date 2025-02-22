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
for(int i = 0;i < n;i++){
    mp[s[i]]++;
}
string k = "nowcoder";
for(auto c : k){
    if(!mp[c]){
        cout << "I AK IOI" << nl;
        return;
    }
    mp[c]--;
}
cout << "happy new year" << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
