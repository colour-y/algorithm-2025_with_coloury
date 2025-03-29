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
string s = "01032025";
map<int,int> mp;

for(auto e : s){
    mp[e - '0']++;
}
int ans = 0;
for(int i = 0;i < n;i++){
    int x;
    cin >> x;
    if(mp[x]) mp[x]--;
if(!mp[0] && !mp[1] && !mp[2] && !mp[3] && !mp[5] && !ans){
 ans = i + 1;
}

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
