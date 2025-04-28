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


void solve(){
int n;
cin >> n;
vector<ll> a(n);
for(auto &e : a){
    cin >> e;
}

ranges::sort(a);
ll k = reduce(all(a),0LL);


int i = 0,m = 0;
while(k >= 0){
k -= primes[i++];
m++;
if(m >= n && k >= 0){
    cout << 0 << nl;
    return;
}
}
k += primes[--i];
m--;
if(m >= n){
    cout << 0 << nl;
    return;
}
int ans = 0;
int j = 0;

while(m < n && n > 1 ){
    k -= a[j++];
n--;
ans++;
if(k < 0){
    m--;
    k += primes[--i];
}
}

cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
cin >> t;
sieve(7000000);
while(t--){
    solve();
}
    return 0;
}
