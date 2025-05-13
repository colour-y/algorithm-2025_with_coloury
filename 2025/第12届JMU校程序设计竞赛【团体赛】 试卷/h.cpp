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
    int n,m;
    cin >> n >> m;
    if(min(n,m) >= 3){
        cout << 0 << nl;
        return;
    }

    if(min(n,m) == 1){
        int e = max(m,n);
        if(e == 1){
            cout << 4 << nl;
        }
        else if(e == 2){
            cout << 12 << nl;
        }else cout << 24 << nl;
        return;
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
