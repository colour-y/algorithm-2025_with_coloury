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
for(int i = 0;i < n - 1;i++){
    if(s[i] == s[i + 1]) {
        cout << 1 << nl;
        return;
    }
}
cout << n << nl;
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
