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

int ans = 0;
int n = s.size();
for(int i = 0;i < n;i++){
if(((i + ans) % 2 == 0 && s[i] != 'i') || ((i + ans) % 2 == 1 && s[i] != 'o') ){
    ans++;
   
}


}
if((ans + n) % 2 == 1) ans++;
cout << ans ;
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
