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
int n,m;
cin >> n >> m;
vector<ll> a(n);
for(auto &e : a){
    cin >> e;
}
int ok = 1;
vector<array<ll,2>> q(n);
while(m--){
    ll x,l,r;
    cin >> x >> l >> r;
    x--;
    if(q[x][0] == 0 && q[x][1] == 0){
q[x][0] = l;
q[x][1] = r;
    }else{
if(q[x][0] > r || q[x][1] < l){
    ok = 0;

}else{
q[x][0] = max(l,q[x][0]);
q[x][1] = min(r,q[x][1]);
}
    }
}

if(!ok){
    cout << -1 << nl;
    return;
}

ll ans = 0;
for(int i = 0;i < n;i++){
    ll x = q[i][0],y = q[i][1];
    if(x == 0 || y == 0) continue;
    if(a[i] < x) ans += x - a[i];
    else if(a[i] > y) ans += a[i] - y;

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
