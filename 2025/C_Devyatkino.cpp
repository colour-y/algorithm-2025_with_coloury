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
 int n ;
 cin >> n;
 for(int ans = 0;ans <= 6;ans++){
    auto s = to_string(n - ans);
    for(auto x : s){
        int d = x - '0';
        if(d <= 7 && 7 - d <= ans){
            cout << ans << nl;
            return;
        }
    }
 }
 cout << 7 << nl;
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
