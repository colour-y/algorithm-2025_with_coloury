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
string s;
cin >> n >> s;
if(count(all(s),s[0]) == n){
    cout << n + (s[0] == '1') << nl;
    return;
}
//

int ans = 0;
char c = '0';
for(int j = 0;j < n;j++){
if(s[j] == c) ans++;
else{
    ans += 2;
    c = (c - '0') ^ 1 + '0'; 
}
}
vector<int> e;
int k = 0;
for(int i = 0;i < n;i++)
{
    if(s[i] == '0') k++;
    else if(k != 0 && s[i] == '1'){
        if(i - k != 0)
        e.push_back(i - 1);
        k = 0;
    }
}

if(k != 0){
    e.push_back(n - 1);

}
if(e.empty()){
    cout << ans << nl;
    return;
}
sort(all(e),[&](auto x,auto y){
 return x < y;
});


if(e[0] != n - 1) ans-=2;
else if(e[0] == n - 1) ans--;

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
