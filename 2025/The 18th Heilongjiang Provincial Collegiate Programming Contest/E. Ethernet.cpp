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
int n,m;
cin >> n >> m;
if(n == m){
    cout << fixed << setprecision(10) << 1.0 / n << nl;
}else{
    cout << fixed << setprecision(10) << 1.0 / (m + 1) << nl;
}
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
