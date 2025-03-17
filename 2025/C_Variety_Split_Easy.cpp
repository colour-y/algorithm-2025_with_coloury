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
vector<int> a(n);
map<int,int> mp;
int ans = 0,res = 0,k = 0;
for(auto &e : a){
    cin >> e;
    if(!mp[e]) res++;
    mp[e]++;
    
}
map<int,int> rp;
for(auto e : a){
    if(!rp[e]){
        rp[e]++;
        k++;
    }
mp[e]--;
if(!mp[e]) res--;

    ans = max(k + res,ans);

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
