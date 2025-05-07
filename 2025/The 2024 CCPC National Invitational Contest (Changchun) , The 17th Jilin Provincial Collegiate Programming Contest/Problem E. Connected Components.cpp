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
map<ll,vector<ll>> mp;
map<ll,int> np;
vector<array<ll,2>> b(n); 
for(int i = 1;i <= n;i++){
    ll x,y;
    cin >> x >> y;
    mp[i - x].push_back(i);
    mp[i - y].push_back(i);
}
ll ans = 0,res = 0;
for(auto v : mp){
for(auto x : v)
{

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
