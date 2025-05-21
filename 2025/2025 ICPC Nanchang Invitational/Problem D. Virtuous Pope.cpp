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
ll a,b,c;
cin >> n >> a >> b >> c;
map<ll,ll> mx,my,mz;
for(int i = 0 ;i < n;i++){
    ll x1,y1,z1,x2,y2,z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    if(x2 < x1) swap(x2,x1);
    if(y2 < y1) swap(y2,y1);
    if(z2 < z1) swap(z2,z1);
    mx[x1]++;
    mx[x2 + 1]--;
    my[y2]++;
    my[y2 + 1]--;
    mz[z1]++;
    mz[z2 + 1]--;
}

ll mxmi = 0;
ll res = 0;
for(auto [x,y] : mx){
    res += y;
}
    mxmi = max(res,mxmi);

res = 0;
for(auto [x,y] : my){
    res += y;
}
    mxmi = max(res,mxmi);

res = 0;
for(auto [x,y] : mz){
    res += y;
}
    mxmi = max(res,mxmi);

cout << mxmi << nl;
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
