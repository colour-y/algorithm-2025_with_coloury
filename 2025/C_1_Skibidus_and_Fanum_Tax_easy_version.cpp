#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
ll n,m;
cin >> n >> m;
vector<ll> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
cin >> m;
for(int i = 0;i < n;i++){
    ll x = min(a[i],m - a[i]);
    if(!i) a[i] = x;
    else if(x >= a[i - 1]) a[i] = x;
    if(i && a[i] < a[i - 1]){
        cout << "NO" << nl;
        return;
    }
}
for(int i = 1;i < n;i++){
    if(a[i] < a[i - 1]){
        cout << "NO" << nl;
        return;
    }
}
cout << "YES" << nl;
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
