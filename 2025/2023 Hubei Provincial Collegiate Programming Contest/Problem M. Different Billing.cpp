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
ll x;
ll k;
cin >> x >> k;
if(k == 0){
    cout << x << " 0 0" << nl; 
    return;
}
if(2500 * x < k || k < 1000){
    cout << -1 << nl;
    return;
}
int a = 0,b = 0,c = 0;
c = k / 2500;
k %= 2500;
if(k != 0 && c == 0){
    cout << -1 << nl;
    return;
}
if(k % 500 != 0){
    cout << -1 << nl;
    return;
}
while(k){
    k += 2500;
    c--;
    b += k / 1000;
    k %= 1000;

    if(c == 0 && k != 0){
        cout << -1 << nl;
        return;
    }
}
a = x - b - c;
if(a < 0){
    cout << -1 << nl;
    return;
}
cout << a << " " << b << " " << c << nl;
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