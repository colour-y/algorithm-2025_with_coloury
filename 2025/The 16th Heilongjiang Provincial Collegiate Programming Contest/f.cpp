#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  vector<int> mi,primes,minp,f;

  void sieve(int n){
    mi.assign(n + 1,1);
    minp.assign(n + 1,0);
    f.assign(n + 1,{});
    f[1] = 1;
    for(int i = 2;i <= n;i++){
        if(!minp[i]){
            mi[i] = i;
            minp[i] = i;
            primes.push_back(i);
            f[i] = 1;
        }

        for(auto &p : primes){
            if(i * p > n) break;
            minp[i * p] = p;
            if(minp[i] == p){
                if(mi[i] * p == i * p){
                    mi[i * p] = mi[i] * p;
                f[i * p] = p * f[i / p];
                }else{
                    mi[i * p] = mi[i] * p;
                    f[i * p] = f[mi[i * p]] * (i / mi[i]);
                }
                break;
            }else{
                f[i * p] = i;
                mi[i * p] = p;
            }
        }
    }
  }


void solve(){
int n;
cin >> n;
sieve(n);
ll ans = reduce(f.begin() + 1,f.end(),0LL);
cout << ans << nl;
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
