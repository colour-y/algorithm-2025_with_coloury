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
ll h;
cin >> n >> h;
vector<array<ll,2>> a(n);
for(int i = 0;i < n;i++){
    ll x,y;
    cin >> x >> y;
    a[i][0] = x;
    a[i][1] = y;

}


sort(all(a),[&](auto x,auto y){
    if(x[0] - x[1] == y[0] - y[1]){
        return x[1] < y[1];
    }
return x[0] - x[1] > y[0] - y[1];
});

int ans = 0;
for(int i = 0;i < n;i++){
    h += a[i][0] - a[i][1];
    if(h > 0) ans++;
    else break;
}
cout << ans << nl;
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
