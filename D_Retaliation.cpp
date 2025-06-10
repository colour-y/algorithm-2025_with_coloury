#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve()
{
int n;
cin >> n;
vector<ll> a(n);
for(auto &e : a){
    cin >> e;
}
if(n == 1){
    cout << "YES" << nl;
    return;
}
ll x = 0,y = 0;
ll k1 = a[0] + a[n - 1],k2 = a[n - 1] - a[0];
if(k1 % (n + 1) != 0 || k2 % (n - 1) != 0){
    cout << "NO" << nl;
    return;
}

k1 /= n + 1;
k2 /= n - 1;

x = (k1 + k2) / 2;
y = (k1 - k2) / 2;
if(x < 0 || y < 0){
       cout << "NO" << nl;
    return;
}
// cout << x << " " << y << nl;
for(int i = 1;i < n;i++){
    if(a[i] != x * (i + 1) + y * (n - i)){
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

