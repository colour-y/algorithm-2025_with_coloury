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
vector<array<int,2>> a(10);
a[1] = {1,1};
a[2] = {1,2};
a[3] = {1,3};
a[4] = {2,1};
a[5] = {2,2};
a[6] = {2,3};
a[7] = {3,1};
a[8] = {3,2};
a[9] = {3,3};
a[0] = {4,2};
string s;
cin >> s;
int ans = 0;
for(int i = 1;i < s.size();i++){
    int c = s[i] - '0';
    int e = s[i - 1] - '0';
    ans += abs(a[c][0] - a[e][0]) + abs(a[c][1] - a[e][1]);
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
