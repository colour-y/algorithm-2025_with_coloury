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
cin >> n;
vector<int> cnt(4);
for(int i = 0;i < n;i++){
    int x;
    cin >> x;
    cnt[x]++;
}

int ans = INT_MAX;
for(int i = 0;i < 4;i++){
int res = cnt[i] + cnt[(i + 1) % 4] * 2 + cnt[(i + 2) % 4] * 3;
// cout << res << nl;
int m = (res + i + 3) % 4;
// cout << 4 - m << nl;
if(m != 0)
ans = min(ans,res + 4 - m);
else ans = min(ans,res);

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
