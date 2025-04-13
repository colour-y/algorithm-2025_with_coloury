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
vector<int> a(n);
for(auto &e : a){
    cin >> e;

}
for(int i = 0;i < n;i++){
    int ans = 0;
    if(i == 0){
ans += 2;
    }
    ans += a[i] - 1;
    ans = min(5,ans);
    cout << ans << " ";
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
