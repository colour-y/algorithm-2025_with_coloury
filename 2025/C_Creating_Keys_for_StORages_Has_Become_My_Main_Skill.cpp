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
int n;
ll x;
cin >> n >> x;
if(n == 1){
    cout << x << nl;
    return;
}
int res = 0;
for(int i = 0;i < n;i++){
    if(i == n - 1){
        if((res | i) == x){
            cout << i << " ";
        }else{
            cout << x << " ";
        }
        break;
    }
if((x | i) == x){
    res |= i;
    cout << i << " ";
} 
else{
    cout << x << " ";
}

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
