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
ll a,b,c,d;
cin >> a >> b >> c >> d;
if(b - a >= d - c){
cout << a << " " << d - 1 << nl;
cout << b << " " << d << nl;
cout << b - 1 << " " << d << nl;
}
else{
    cout << a << " " << d << nl;
    cout << a << " " << d - 1 << nl;
    cout << a + 1 << " " << c << nl;
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
