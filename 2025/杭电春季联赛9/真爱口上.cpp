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
string a,b;
cin >> a >> b;
set<char> st = {'a','e','i','o','u'};
auto cph = [&](auto s) -> int{
int res = 0;
for(int i = 0;i < s.size();i++){
if(st.find(s[i]) != st.end()) res++;
else if(i && s[i] == s[i - 1] && (i == s.size() - 1|| s[i] != s[i + 1])) res++;

}
return res;
};
cout << cph(a) << " " << cph(b) << nl;
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
