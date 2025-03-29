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
int n;
cin >> n;
vector<ll> a(n),b(n);
for(auto &e : a){
    cin >> e ;
}
for(auto &e : b){
    cin >> e;
}

ranges::sort(a);
ranges::sort(b);

if(a == b){
    cout << int(1e9) << nl;
    return;
}

ll sua = accumulate(all(a),0LL);
ll sub = accumulate(all(b),0LL);

ll df = sua - sub;
if(df <= 0){
    cout << -1 << nl;
    return;
}

auto na = a;
auto check = [&](ll k){
  if(k > int(1e9)){
    return false;
  }
  na = a;
  for(auto &x : na){
    x %= k;
  }
  ranges::sort(na);
  return na == b;

};

for(ll i = 1;i * i <= df;i++){
    if(df % i == 0){
        if(check(i)){
            cout << i << nl;
            return;
        }

        if(check(df / i)){
            cout << df / i << nl;
            return;
        }
    }
}
cout << -1 << nl;
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
