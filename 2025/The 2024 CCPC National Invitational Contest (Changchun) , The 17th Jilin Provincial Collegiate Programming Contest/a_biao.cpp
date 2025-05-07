#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  int N = 1e7 + 7;
vector<ll> f(N);

void sieve(){
    for(int i = 3;i <= 1e7 + 7;i++){
        f[i] = f[i - 1] + f[i - 2];
    }
}

void solve(){
string s;
cin >> s;
reverse(all(s));
ll ans = 0;
ll k = 1;
ll res = 0;
for(auto c : s){
if(c == '1') ans += k;
k *= 2;
}
map<ll,ll> mp;
for(ll i = 1;i <= ans;i++){
ll x = i;
ll y = 0;
while(x){
if(x & 1) y++;
x >>= 1;
}
mp[y]++;
res += f[y];
}

for(auto [x,y] : mp){
    cout << x << " " << y << nl;
}
cout << res << nl;


}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
f[0] = 1;
f[1] = 1;

sieve();
while(t--){
    solve();
}
    return 0;
}
