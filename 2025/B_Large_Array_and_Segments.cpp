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
int n,k;
ll x;
cin >> n >> k >> x;
vector<ll> a(n);
for(int i = 0 ;i < n;i++){
    cin >> a[i];
}

ll su = reduce(all(a),0LL);
ll msu = su * k;
ll ans = 0;
while(msu - su >= x){
    msu -= su;
    ans += n;
}
int i = 0;
while(msu  >= x){
msu -= a[i % n];
i++;
ans++;
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
