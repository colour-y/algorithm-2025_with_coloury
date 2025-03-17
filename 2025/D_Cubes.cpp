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
    
  ll N;
  std::cin >> N;
  
  for (ll d = 1; d * d * d <= N; d++) {
      if (N % d != 0) {
          continue;
      }
      ll p = N / d - d * d;
      if (p % 3 != 0) {
          continue;
      }
      p /= 3;
      
      ll x = (d + std::sqrt(d * d + 4 * p)) / 2 + 0.5;
      ll y = x - d;
      if (y > 0 && i128(x) * x * x - i128(y) * y * y == N) {
          std::cout << x << " " << y << "\n";
          return;
      }
  }
  
  std::cout << -1 << "\n";
  
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
