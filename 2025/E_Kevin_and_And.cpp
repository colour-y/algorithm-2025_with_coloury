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
int n,m,k;
cin >> n >> m >> k;
vector<ll> a(n),b(m);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
for(int i = 0;i < m;i++){
    cin >> b[i];
}

if(k == 0){
    cout << accumulate(a.begin(),a.end(),0LL) << nl;
    return;
}
ranges::sort(a);
ranges::sort(b);
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
