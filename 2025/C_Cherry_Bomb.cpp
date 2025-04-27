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
ll k;
cin >> n >> k;
vector<ll> a(n),b(n);
ll mi = INT_MAX,mx = INT_MIN;
for(auto &e : a){
    cin >> e;
    mx = max(mx,e);
    mi = min(mi,e);
}
set <ll> st;
vector<ll> d;
for(int i = 0;i < n;i++){
    cin >> b[i];
    if(b[i] != -1){
        st.insert(a[i ] + b[i]);
        d.push_back(a[i] + b[i]);
    }
}

if(st.size() == 1){
    ll c = d[0];
    if(mi + k < c || mx > c) cout << 0 << nl;
    else 
  cout << 1 << nl;
  return;
}

if(st.size() > 1){
    cout << 0 << nl;
    return;
}

{
ll ans = k - (mx - mi) + 1;
cout << ans << nl;
}


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
