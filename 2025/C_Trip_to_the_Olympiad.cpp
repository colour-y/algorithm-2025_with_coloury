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
int l,r;
cin >> l >> r;
int a = 0,b = 0,c = 0;
for(int i = 29;i >= 0;i--){
   if((l ^ r) >> i & 1){
     b |= 1 << i;
    a |= (1 << i) - 1;
    break;
   }
   else {
    a |= l & (1 << i);
    b |= l & (1 << i);
   }
}
c = l;
while(c == a || c == b){
    c++;
}
cout << a << " " << b << " " << c << nl;


}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
