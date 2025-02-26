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
int n,m;
cin >> n >> m;
int x,y;
for(int i = 0;i < m;i++){
  int z;
  cin >> x >> y >> z;
}
if((y - x) % 2)
{
  for(int i = n;i > 0;i--){
    cout << i << " ";
  }
  cout << nl;
}else{
  for (int i = 1; i <= n; i += 2) {
    if (i < n) {
      cout << n - i << " " << n - i + 1 << " ";
    } else {
      cout << "1 ";
    }
  }
  cout << nl;
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
