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
if(n < 3){
    cout << 0 << nl;
    return;
}else if(n == 3){
    cout << 1 << nl;
    return;
}else if(n == 4){
    cout << 4 << nl;
    return;
}

int ans = 4 + (n - 4) * 2;
cout << ans << nl;

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
