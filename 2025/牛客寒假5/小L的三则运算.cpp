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
ll n;
char c;
cin >> n >> c;
if(c == '-'){
    cout << n + 1 <<  " " << 1 << nl;
}else if(c == '+'){
    cout << n - 1 << " " << 1 << nl;
}else{
    cout << n << " " << 1 << nl;
}
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
