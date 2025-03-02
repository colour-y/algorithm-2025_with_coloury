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
string s;
cin >> s;
for(int k = n;k > 0;k--){
vector<int> a(k);
for(int i = 0;i < n;i++){
    a[i % k] ^= '1' - s[i];
}
if(a == vector(k,a[0])){
    cout << k << nl;
    return;
}
}
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
