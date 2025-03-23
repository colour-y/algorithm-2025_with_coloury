#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  ll calc(ll x){
 for(int i = 0;i < 31;i++){
      if((1LL << i) > x){
        return (1LL << i) - x;
      } 
 }
 return 0;
  }
    
void solve(){
ll x,y;
cin >> x >> y;
if(x == y){
    cout << -1 << nl;
    return;
}
cout << (x > y ? calc(x) : calc(y)) << nl;

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
