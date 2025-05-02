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
map<string,int> np;
map<string,map<string,int>> mp;
for(int i = 0;i < n;i++)
{
string a,b,c;
cin >> a >> b >> c;
if(c == "accepted"){
    if(!mp[a][b]) mp[a][b] = 1,np[b]++;
}
}
int mx = 0;
string ans = "A";
for(auto [x,y] : np){
    // cout << x << ' ' << y << nl;
if(y > mx) ans = x,mx = y; 
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
