#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  vector<int> minp, primes;
void sieve(int n)
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
cin >> n ;
vector<ll> a(n);
for(auto &i : a){
    cin >> i;

}
ranges::sort(a);
vector<int> cnt(n + 1);
int k = 0;
sieve(n);

ll ans = 0;
for(auto x : a){
int p = minp[x];
if(x == p){
    ans += k - cnt[p];
    k++;
    cnt[p]++;
}else{
    int q = minp[x / p];
    if(x != p * q){
        continue;
    }
    ans++;
    if(p == q){
        ans += cnt[x];
        ans += cnt[p];
    }else{
        ans += cnt[x];
        ans += cnt[p];
        ans += cnt[q];
    }
    cnt[x]++;
}

}
cout << ans << nl;
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
