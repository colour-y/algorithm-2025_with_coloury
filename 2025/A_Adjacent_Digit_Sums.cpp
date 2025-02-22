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
int x,y;
cin >> x >> y;
if(y >= x){
    if(y == x + 1){
        cout << "Yes" << nl; 
    }else{
     cout << "No" << nl;
    }
}else if((x + 1 - y) % 9 == 0) cout << "Yes" << nl;
else cout << "No" << nl;
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
