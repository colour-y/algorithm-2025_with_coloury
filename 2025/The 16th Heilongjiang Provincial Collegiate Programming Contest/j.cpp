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
cin >> n >> m;
map<int,int> mp,np;

for(int i = 0;i < m;i++){
int x,y;
cin >> x >> y;
mp[x]++;
np[y]++;
}
int ans = n;
int k = 0;
for(auto [x,y] : mp){
if(y == n) k = 1;

}
for(auto [x,y] : np){
    if(y == n)  k = 1;
    
    }
cout << ans - k << nl; 
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
