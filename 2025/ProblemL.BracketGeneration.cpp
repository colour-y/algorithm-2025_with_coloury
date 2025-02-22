#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
const int mod = 998244353;
  #define all(x) (x).begin(), (x).end()
void solve(){
string s;
cin >> s;
vector<ll> v;
int k  = 0;
for(int i = 0;i < s.size() ;i++){
    if(s[i] == ')'){
        if(s[i - 1] == '(') k++;
        else v.push_back(k);
    }
}
int res = 1;
ranges::reverse(v);
for(int i = 0;i < v.size();i++){
    res = (res * (k - v[i] + 1 + i)) % mod;
}
cout << res << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
