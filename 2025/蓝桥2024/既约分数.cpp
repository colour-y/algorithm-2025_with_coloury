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
int ans = 0;
for(int i = 1;i <= 2020;i++){
    for(int j = i + 1;j <= 2020;j++){
        if(gcd(i,j) == 1){
            ans++;
        
    }

}

}
cout << ans * 2 << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}
