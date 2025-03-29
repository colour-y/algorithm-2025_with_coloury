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
string s,c;
cin >> n >> s >> c;
int au = count(all(s),'0') + count(all(c),'0');

if(au < n){
    
    cout << "No" << nl;
    return;
}
int res = 0,ans = 0;

for(int i = 0;i < n;i++){
if(i % 2){
    if(s[i] == '0'){
        res++;
    }
    if(c[i] == '0'){
        ans++;
    }
}else{
    if(s[i] == '0'){
        ans++;
    }
    if(c[i] == '0'){
        res++;
    }
}
}

if(n % 2){
    if(ans < n / 2 + 1 || res < n / 2){
        cout << "No" << nl;
        return;
    }
}else if(n % 2 == 0){
    if(ans < n / 2 || res < n / 2){
        cout << "No" << nl;
        return;
    }
}

cout << "Yes" << nl;
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
