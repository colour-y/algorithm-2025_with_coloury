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
ll k;
cin >> n >> k;
ll sum = 0;
for(int i  =0 ;i < n;i++){
  int e;
  cin >> e;
  sum += e;
}
if(sum == k){
  cout << n << nl;
}else{
  cout << n - 1 << nl;
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
