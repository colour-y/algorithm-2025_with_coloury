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
int n,m;
cin >> n >> m ;
vector<int> a(n),b(m);
for(auto &e : a){
    cin >> e;
}
for(auto &e : b){
    cin >> e;
}

int i = 0,j = 0;
ll r = 0,k = 0;
int ans = 0;
while(i <= n && j <= m){
if(r == 0 && k == 0){
    
r += a[i++];
k += b[j++];
}else if(r == k){
    
    r = 0;
    k = 0;
}else if(r < k){
    r += a[i++];
    ans++;
}else if(k < r){
    k += b[j++];
    ans++;
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
