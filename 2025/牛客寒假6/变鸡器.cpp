#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n;
cin >> n;
string s;
cin >> s;
if(n < 7 || (n - 7) % 2){
    cout << "NO" << nl;
return;
}
if(n == 7){
    if(s == "CHICKEN"){
        cout << "YES" << nl;
    }
    else cout << "NO" << nl;
    return;
}
int j = 0;
string res = "CHICKEN";
for(int i = 0;i < n;i++){
if(s[i] == res[j]){
    j++;
}
if(j == 7) break;
}


if(j != 7){
    cout << "NO" << nl;
    return;
}


map<char,int> mp;
int mx = 0;
for(int i = 0;i < 7;i++){
    mp[res[i]]--;
}
for(int i = 0;i < n;i++){
mp[s[i]]++;
mx = max(mx,mp[s[i]]);
}

if(mx > (n - 7) / 2){
    cout << "NO" << nl;
    return;
}
cout << "YES" << nl;
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
