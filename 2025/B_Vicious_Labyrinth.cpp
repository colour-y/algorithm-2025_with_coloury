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
int n,k;
cin >> n >> k;
if(n == 2){
    cout << 2 << " " << 1 << nl;
    return;
}
if(k % 2 == 1){
    for(int i = 0;i < n - 1;i++){
        cout << n << " ";
    }
    cout << n - 1 << nl;
}
else{
    for(int i = 0;i < n - 2;i++){
        cout << n - 1 << " ";
        
    }
    cout << n << " " << n - 1 << nl;
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
