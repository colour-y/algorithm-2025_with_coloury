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
cin >> n ;
string s;
cin >> s;
auto check = [&](string s){
  map<char,int> pos;
  int n = s.size(),res = 0;
  for(int i = 0;i < n;i++){
    if(pos.contains(s[i])){
      res = max(res,pos[s[i]] + 1);
      res = max(res, n - i);
    }
    pos[s[i]] = i;
  }
  if(res == 1) res = 0;
  return res;
};
cout << check(s) << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
