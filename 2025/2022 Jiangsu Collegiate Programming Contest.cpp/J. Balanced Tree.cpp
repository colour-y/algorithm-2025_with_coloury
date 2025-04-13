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
i64 ans = 1;
if(n >= 149){
    cout << 0 << nl;
    return;
}
auto dfs = [&](this auto&& dfs,ll k) -> void{

if(k == 0 || k == 1) return;
k--;

if(k == 1){
    ans *= 2;
}
else if(k % 2 == 1){
    ans *= 2;
    k--;
    dfs(k / 2 + 1);
    dfs(k / 2);
}else {
    dfs(k / 2);
    dfs(k / 2);
}

};

dfs(n);
// if(ans == 0) cout << n << nl;

cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
cin >> t;

while(t--){
//  for(int i = 110;i <= 200;i++)
    solve();
}
    return 0;
}
