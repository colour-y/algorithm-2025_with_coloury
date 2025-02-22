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
int n,m;
cin >> n >> m;
vector<ll> a(n),b(m);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
for(int i = 0;i < m;i++){
    cin >> b[i];
}
ranges::sort(b);
if(b[0] < 2 * a[0]) a[0] = b[0] - a[0];
for(int i = 1;i < n;i++){
    auto it = lower_bound(all(b),a[i] + a[i - 1]);
    if(it != b.end()){
        if(a[i] >= a[i - 1] && *it - a[i] >= a[i]) continue;
        a[i] = *it - a[i];
    }
}
cout << (is_sorted(all(a)) ? "YES" : "NO") << nl;
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
