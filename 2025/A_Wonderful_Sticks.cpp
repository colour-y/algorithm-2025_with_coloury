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
string s;
cin >> s;
vector<int> ans(n);
int k = 1;
for(int i = n - 2;i >= 0;i--){
    if(s[i] == '<') ans[i + 1] = k++;
}
ans[0] = k++;
int mx = 0;
for(int j = 0; j < n;j++){
    if(!ans[j]) ans[j] = k++;
   
}
for(auto e : ans)
{
    cout << e << " ";
}
cout << nl;
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
