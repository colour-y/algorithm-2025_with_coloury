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
int n,k;
cin >> n >> k;
vector<int> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}


ll ans = reduce(all(a),0LL);
if(ans >= k){
    if(k % 2 == 1) k++;
    cout << ans - k / 2 << nl;
}else cout << 0 << nl;

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
