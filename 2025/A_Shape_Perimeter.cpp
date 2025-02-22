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
int a = 0 ,b = 0;
cin >> a >> b;
int l = a,  r = b;
for(int i = 0;i < n - 1;i++){
    int x,y;
    cin >> x >> y;
    a += x;
    b += y;
}
a += m,b += m;
cout << 2 * (a - l) + 2 * (b - r) << nl;
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
