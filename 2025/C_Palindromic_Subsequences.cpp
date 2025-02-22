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
int n;
cin >> n;
if(n == 6){
    cout << "1 1 2 3 1 2" << nl;
    return;
}
int m = n;
m -= n % 2;
if(n % 2 == 1){
    cout << 1 << " ";
}
int res  = 1;
for(int i = 0;i < m / 2;i++){
cout << res << " ";
res++;
}
 res  = 1;
for(int i = 0;i < m / 2;i++){
cout << res << " ";
res++;
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
