```cpp
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
map<int,int> mp;
for(int i = 0;i < n ;i++){
    cin >> a[i];
   for(int j = sqrt(a[i]);j >= 2;j--){
    if(a[i] % (j * j) == 0) a[i] /= j * j;
   }
   mp[a[i]]++;
}

vector<int> cnt;
for(auto [x,y] : mp){
  cnt.push_back(y);
}

int ans = 0;
sort(cnt.begin(),cnt.end(),greater());
for(int i =0 ;i < cnt.size() && k;i++){
if(cnt[i] >= k){
  ans += k * (k - 1) / 2;
}else{
  ans += cnt[i] * (cnt[i] - 1) / 2;
  k -= cnt[i];
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

```
