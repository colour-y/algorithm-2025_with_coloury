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
ll n,a,b;
cin >> n >> a >> b;
if (n == 1) {
    cout << "智慧潍坊，生生不息" << nl;
    return;
}

if(n % a == 0 || (n - 1) % b == 0){
    cout << "智慧潍坊，生生不息" << nl;
    return;
}

ll k = 1;
while(k <= n){
    k *= a;
    if((n - k) % b == 0){
        cout << "智慧潍坊，生生不息" << nl;
        return;
    }
}
k /= a;
k = n - k;
if(k % b == 0){
    cout << "智慧潍坊，生生不息" << nl;
    return;
}
cout << "规划未达，创新不止" << nl;
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
