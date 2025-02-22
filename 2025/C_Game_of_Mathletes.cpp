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
int n,k;
cin >> n >> k;
vector<int> a(n);
map<int,int> mp;
for(int i = 0 ;i < n;i++){
    cin >> a[i];
mp[a[i]]++;
}
int ans = 0;
int res = 0;
for(auto &[x,y] : mp){

 if(mp[k - x] && x < k){
    if(k % 2 == 0 && k - x == x){
ans += y / 2;
y = 0;

    }
else if(y >= mp[k - x]){
    ans += mp[k - x];
    mp[k - x]  = 0;
    y = 0;
}
else if(y < mp[k - x]){
    ans += y;
    y = 0;
    mp[k - x] = 0;
}
}
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
