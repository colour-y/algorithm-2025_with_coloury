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
cin >> n ;
if(n % 2 == 0){
    cout << -1 << nl;
    return;
}

if(n == 3){
    cout << "3 2 1 "<< nl;
    return;
}

vector<int> ans(n + 1);
for(int i = n;i >= 2 ;i--){
    ans[i] = i - 1;
}

ans[1] = n;
for(int i = 1;i <= n;i++){
    cout << ans[i] << " ";
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
