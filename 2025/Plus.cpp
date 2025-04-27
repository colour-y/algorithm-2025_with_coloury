#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  vector<ll> minp, primes;
  void sieve(ll n)
  {
      minp.assign(n + 1, 0);
      primes.clear();
      for (int i = 2; i <= n; i++)
      {
          if (minp[i] == 0)
          {
              minp[i] = i;
              primes.push_back(i);
          }
          for (auto p : primes)
          {
              if (i * p > n)
              {
                  break;
              }
              minp[i * p] = p;
              if (p == minp[i])
              {
                  break;
              }
          }
      }
  }
  
  

void solve(){
int n;
cin >> n;
vector<set<int>> st(n);
st[0].insert(st[1]);
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
