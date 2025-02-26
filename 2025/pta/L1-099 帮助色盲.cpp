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
int n,m;
cin >> n >> m;
if(n == 2 || m == 1){
    cout << "-" << nl;
}else if(n == 0){
    cout << "biii" << nl;
}else{
    cout << "dudu" << nl;
}
if(n == 0 || n == 2){
    cout << "stop" ;
}else{
    cout << "move" ;
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
