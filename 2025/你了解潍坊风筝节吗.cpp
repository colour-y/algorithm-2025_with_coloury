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
cin >> n;
n = 2 * n - 1;
if(n % 2 == 1){
    for(int i = 1;i <= n;i += 2){
        cout << i << " ";
    }
    for(int i = n - 1;i > 0; i -= 2){
        cout << i << " ";
    }
}else{
    for(int i = 2;i <=n;i += 2){
        cout << i << " ";
    }
    for(int i = n - 1;i > 0;i -= 2){
        cout << i << " " ;
    }
}
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
