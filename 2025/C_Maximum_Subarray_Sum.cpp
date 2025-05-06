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
string s;
cin >> s;
vector<ll> a(n);
ll su = 0;
int res = 0;
int ok = 1;
ll mm = 0;
for(int i = 0;i < n;i++)
{
    ll x;
    cin >> x;
    a[i] = x;
    if(s[i] == '0')
    {
        res++;
    }
if(s[i] == '1')
    su += a[i];
    if(su < 0 || s[i] == '0') su = 0;
    if(su > k){
        ok = 0;
    }
    mm = max(su,mm);
}

if(su > k  || !ok || (res == 0 && mm != k))
{
    cout << "No" << nl;
    return;
}
cout << "Yes" << nl;
ll ans = 0;
ll g = 0;
ll h = 0;
ll kt = 0;
int c = -1 ;
// for(auto e : a){
//     cout << e << " ";

// }
for(int i = 0;i < n;i++){
    if(s[i] == '0' && res > 1){
        res--;
        a[i] = -10000000000;
        ans = 0;
       
    }
    else if(res == 1 && s[i] == '1'){
        ans += a[i];
        if(ans < 0) ans = 0;
        
    }else if(s[i] == '0'){
        c = i;
        res--;
    }else if(res == 0){

    h += a[i];
    kt = max(h,kt);
    
    }

}

ans += kt;
// cout << ans << " " << kt << nl;
if(c != -1)
a[c] = k - ans;



for(auto e : a){
    cout << e << " ";

}
cout << nl;

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
