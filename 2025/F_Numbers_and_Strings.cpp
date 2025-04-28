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

map<string,int> mp;
for(int i = 1;i <= n;i++){
    string s;
 s += to_string(i);
 s += to_string(i + 1);
 sort(all(s));
 mp[s]++;
}

for(auto [x,y] : mp){
    if(y >= 2)
    cout << x << " " << y << nl;
}
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
