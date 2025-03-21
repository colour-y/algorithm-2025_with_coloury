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
vector<ll> a(n),b(n);
for(int i = 0;i < n;i++)
{
cin >> a[i] >> b[i];
}

ranges::sort(a);
ranges::sort(b);

vector<ll> prea(n),preb(n);
prea[0] = a[0];
preb[0] = b[0];
for(int i = 1;i < n;i++)
{
    prea[i] = prea[i - 1] + a[i];
    preb[i] = preb[i - 1] + b[i];
}
ll ans = INT_MAX;
for(int i = 0 ;i < m;i++){
    ll x,y;
    cin >> x >> y;
    ll res = 0;
    auto it = lower_bound(all(a),x);
    auto rt = lower_bound(all(b),y);
    int l = it - a.begin();
    int r = rt - b.begin();
    if(l != n){
if(l - 1 >= 0){
    res += l * x - prea[l - 1];
    res += prea[n - 1] - prea[l - 1] - (n - l) * x;
}else{
res += prea[n - 1] - n * x;
}


    }else{
        res += n * x - prea[n - 1];
     
    }

if(r != n){
if(r - 1 >= 0){
res += r * y - preb[r - 1];
res += preb[n - 1] - preb[r - 1] - (n - r) * y;
}
else{
res += preb[n - 1] - n * y;
}
}else{
    res += n * y - preb[n - 1];
   
}

    ans = min(ans,res);
    
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
