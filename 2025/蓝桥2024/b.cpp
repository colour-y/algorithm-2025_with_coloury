#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  bool check(int a,int b){
    if(a%b==0 && (a/b)%2==0)return true;
    return false;
}


void solve(){
  long long x=343720,y=233333;
  long long t=1;
  long long lx,ly;
  while(1){
      lx=15*t;
      ly=17*t;
      if(check(lx,x) && check(ly,y))break;
      t++;
  }
  cout<<setprecision(2)<<fixed<< sqrt(lx*lx+ly*ly) ;
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
