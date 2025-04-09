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

if(s.size() == 1){
    cout << 0 << nl;
    return;
}
char c = s[0];
int k = 0;
for(int i = 1;i < s.size();i++){
if( s[i] != '0'){
    c = s[i];
    k = i;
}

}
int n = count(s.begin(),s.begin() + k,'0');
if(n != 0){
    cout << s.size() - n - 1 << nl;
}else cout << s.size() - 1 << nl;
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
