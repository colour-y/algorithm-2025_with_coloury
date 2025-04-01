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
ll r,b,m;
cin >> r >> b >> m;
ll sum = r + 2 * b + 4  * m;
if(sum <= 3){
    cout << "Alice" << nl;
    return;
}
if(sum % 4 == 0){
    cout << "Bob" << nl;
    return;
}

cout << "Alice" << nl;

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
