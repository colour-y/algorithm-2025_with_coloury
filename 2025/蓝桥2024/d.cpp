#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()


    
  i64 power(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b /= 2, a = i128(a) * a ) {
    if (b % 2) {
    res = i128(res) * a;
    }
    }
    return res;
    }
  
    

void solve(){
int n;
ld k;
cin >> n >> k;

for(int i = 0;i < n;i++){
  k *= 2;
}
cout << lround(k) << nl;

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
