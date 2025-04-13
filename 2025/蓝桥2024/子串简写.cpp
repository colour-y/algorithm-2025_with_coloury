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
int k;
string s;
char c1,c2;
cin >> k >> s >> c1 >> c2;
int n = s.size();
vector<int> a(n + 1);
 for(int i = n - 1;i >= 0;i--){
  a[i] = a[i + 1];
if(s[i] == c2){
    a[i]++;
}
 }
 
int ans = 0;
for(int i = 0;i < n - k + 1;i++){
    if(s[i] == c1 ){
ans += a[i + k - 1];

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
