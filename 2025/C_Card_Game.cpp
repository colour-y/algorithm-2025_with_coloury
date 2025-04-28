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
if(n == 2){
    if(s[0] == 'A' && s[1] == 'B'){
        cout << "Alice" << nl;
        return;
    }
    cout << "Bob" << nl;
    return;
}

if((s[n - 1] == 'A' && s[n - 2] == 'A') || (s[n - 1] == 'A' && s[0] == 'A') ){
    cout << "Alice" << nl;
    return;
}
if(count(all(s),'A') == n - 1 && s[n - 1] == 'B'){
    cout << "Alice" << nl;
    return;
} 
cout << "Bob" << nl;
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
