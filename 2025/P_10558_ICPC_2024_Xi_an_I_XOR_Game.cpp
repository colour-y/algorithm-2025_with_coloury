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
vector<ll> a(n);
for(auto &r : a)
{
    cin >> r;
}
string ans = string(n,'0');
ll e = reduce(all(a),0);
if(e % 2 == 1){
    for(int i = 0 ;i < n;i++){
        cout << 1;
    }
    return;
}

int ok = 0;
for(int i = n - 1;i >= 0;i--){
    if(a[i] % 2 == 1 && !ok){
        ans[i] = '1';
        ok = 1;
    }
    else if(a[i] % 2 == 1 && ok){
        ok = 0;
}
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
