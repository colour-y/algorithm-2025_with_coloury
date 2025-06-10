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
int n,m;
cin >> n >> m;
vector<int> f(n + 1);
f[1] = 1;
f[2] = 2;

for(int i = 3;i <= n;i++){
    f[i] = f[i - 2] + f[i - 1];
}
int k = f[n];
int c = f[n - 1];
while(m--){
int x,y,h;
cin >> x >> y >> h;
if(x >= k && y >= k && h >= k && (x >= k + c || y >= k + c || h >= k + c)){
cout << 1;
}
else{
    cout << 0;
}
}
// cout << nl;
// cout << f[n] ;
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

