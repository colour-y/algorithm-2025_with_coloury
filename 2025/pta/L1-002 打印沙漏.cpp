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
char c;
cin >> c;
int l = n;
int k = 1;
n++;
n /=2;
while(k * k <= n){
k++;
}
k--;
int m = k;
int x = 0;
while(m){
    cout << string(x,' ') ;
    cout << string(2 * m - 1,c) << nl;

   m--;
   x++;
}
m = 2;
x -= 2;
while(m <= k){
    cout << string(x,' ') ;
    cout << string(2 * m - 1,c) << nl;

    x--;
    m++;
}
cout << l - k * k * 2 + 1 << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
