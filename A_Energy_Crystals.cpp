#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve()
{
int n;
cin >> n;
if(n == 1){
    cout << 3 << nl;
    return;
}

if(n % 2){
    n--;
}
int k = 0;
while(n){
    n /= 2;
    k++;
}

cout << k * 2 + 1<< nl;
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

