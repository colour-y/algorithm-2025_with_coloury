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
int c = 2;
if(n == 1 || n % 4 == 0){
    cout <<"impossible" << nl;
    return;
}
if(n == 2){
    cout << "1 0" << nl;
    return;
}
if(n == 3){
    cout << "1 0 2" << nl;
    return;
}
cout << "1 0 2 4 ";
for(int i = 3,k = 1;i < n;i++,k++){
if(k % 4 == 0){
    cout << i + 1 << " ";
    i--;
    continue;
}
if(i  % 4 == 0) i++;
if(i == n) break;
cout << i << " ";
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
