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
int n;
ll b,c;
cin >> n >> b >> c;
vector<pair<ll,ll>> a(n);
for(int i = 0;i < n;i++){
cin >> a[i].first >> a[i].second;
}


if(b <= c){
    ll ans = 0;

    for(int i = 1;i < n;i++){
        if(a[i].first < a[i - 1].first || a[i].second < a[i - 1].second) ans++;
     
    }
    cout << ans * b << nl;
}else{





    
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
