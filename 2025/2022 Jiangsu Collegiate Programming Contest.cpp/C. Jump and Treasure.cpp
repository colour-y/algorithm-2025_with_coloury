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
int n,q,x;
cin >> n >> q >> x;
vector<ll> a(n);
for(auto &e : a)
{
    cin >> e;
}
while(q--){
    int y;
    cin >> y;
    if(y < x){
        cout << "Noob" << nl;
        continue;
    }
    
}

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
