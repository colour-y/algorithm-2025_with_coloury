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
    for (ll i = 2; i <= n; i++)
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

i64 power(i64 a, i64 b)
{
    i64 res = 1;
    for (; b; b /= 2, a = i128(a) * a)
    {
        if (b % 2)
        {
            res = i128(res) * a;
        }
    }
    return res;
}




void solve(){
cout << gcd(gcd(365788422120542814 ,182894211060271407),731576844241085628 ) << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
cin >> t;
// sieve(7000000);
while(t--){
    solve();
}
    return 0;
}
