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
int k = sqrt(n);
if(k * k != n){
    cout << "No" << nl;
    return;
}

k = 0;
while(n){
    k += n % 10;
    n /= 10;
}

int e = sqrt(k);
if(e * e != k){
     cout << "No" << nl;
    return;
}

 cout << "Yes" << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}

