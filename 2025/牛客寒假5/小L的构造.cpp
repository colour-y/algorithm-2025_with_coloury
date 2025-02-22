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

if(n <= 3) cout << 0 << nl;
else if(n == 4 || n == 5){
    cout << 1 << nl;
    cout << "2 3 4" << nl;
}
else{
   int p = n / 3;
   cout << p << nl;
    if(p % 2 == 0){
        for(int i = 1;i + 5 <= n;i += 6){
            cout << i << " " << i + 1 << " " << i + 3 << nl;
            cout << i + 2 << " " << i + 4 << " " << i + 5 << nl;

        }
    }else{
        cout << "1 2 4" << nl << "6 7 8" << nl << "3 5 9" << nl;
        for(int i = 10 ;i + 5 <= n;i += 6){
            cout << i << " " << i + 1 << " " << i + 4 << nl;
            cout << i + 2 << " " << i + 3 << " " << i + 5 << nl;
        }
    }
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
