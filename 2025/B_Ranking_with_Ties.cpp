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
cin >> n ;
vector<int> a(n);
for(auto &e : a){
    cin >> e;
}
auto b = a;
sort(all(b),greater());
vector<int> ans(n);
ans[0] = 1;
for(int i = 1;i < n;i++){
    if(b[i] == b[i - 1]) ans[i] = ans[i - 1];
    else ans[i] = i + 1;
}
map<int,int> mp;
for(int i =0 ;i < n;i++){
mp[b[i]] = ans[i];
}
for(int i = 0;i < n;i++){
    cout << mp[a[i]] << nl;
}
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
