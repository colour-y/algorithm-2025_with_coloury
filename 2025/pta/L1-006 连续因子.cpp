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
int l = 0;
int ans = 0;
for(int i = 2;i <= sqrt(n) + 1;i++){
    int pow = 1;
    int j;
    for(j = i;j <= sqrt(n) + 1;j++){
        pow *= j;
        if(n % pow != 0){
break;
        }

    }
    if(j - i > ans){
        ans = j - i;
        l = i;
    }
}
if(l == 0){
    cout << 1 << nl << n;
}else{
    cout << ans << nl;

    for(int i = 0;i < ans;i++){
        cout << l + i;
        if(i != ans - 1) cout << '*';
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
//本题答案参考自https://www.liuchuo.net/archives/1590