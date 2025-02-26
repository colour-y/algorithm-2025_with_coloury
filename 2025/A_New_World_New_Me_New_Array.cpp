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
int n,k,p;
cin >> n >> k >> p;
k = abs(k);
if(n * p  < k){
    cout << - 1 << nl;
    return;
}

if(k % p){
    cout << k / p + 1 << nl;
}
else{
    cout << k / p << nl;
}
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
