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
string s;
cin >> s;
int n = s.size();
vector<array<int,2>> a;
for(int i = 0;i < n - 2;i++){
    if(s.substr(i,3) == "ABC" && i % 2 == 0) a.push_back(i + 1,1);
    else if(s.substr(i,3) == "ABC" && i % 2 == 1) a.push_back(i + 1,0);
}
int k = 0;
int m = a.size();
for(int i = 0;i < m;i++){
for(int j = m - 1;j >= i;j--){
    if()
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
