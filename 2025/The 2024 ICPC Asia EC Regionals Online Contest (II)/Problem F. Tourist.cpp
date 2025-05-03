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
ll k = 1500;
for(int i = 0;i < n;i++)
{
    ll x;
    cin >> x;
    k += x;
    if(k >= 4000) {
    cout << i + 1 << nl;
return;
}

}
cout << -1 << nl;
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
