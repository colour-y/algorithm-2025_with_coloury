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
int n,k;
cin >> n >> k;
string s;
cin >> s;
if(n == 1){
    cout << "NO" << nl;
    return;
}
if(string(n,s[0]) == s){
    cout << "NO" << nl;
    return;
}
if(k == 0){
    for(int i = 0;i < n / 2;i++){
        if(s[i] < s[n - i - 1]){
            cout << "YES" << nl;
            return;
        }
        else if(s[i] > s[n - i - 1]){
            cout << "NO" << nl;
            return;
        }

    }
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
