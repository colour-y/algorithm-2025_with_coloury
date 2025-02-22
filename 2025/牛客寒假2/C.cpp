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
int n,k;
cin >> n >> k;
if(n == k) {
cout << "NO" << nl;
return;
}
if(n - k > 26){
  cout << "NO" << nl;
  return;
}
cout << "YES" << nl;
for(int i = 0;i < n;i++){
  cout << char('a' + i % (n - k));
}
cout << nl;
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
