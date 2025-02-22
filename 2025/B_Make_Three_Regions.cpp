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
cin >> n ;
string s[2];
cin >> s[0] >> s[1];

int ans = 0;
for(int i = 1;i < n - 1;i++){
    for(int j = 0;j < 2;j++){
        if(s[j][i] == '.' && s[j][i - 1] == '.' && s[j][i + 1] == '.' && s[j ^ 1][i] == '.' && s[j ^ 1][i - 1] == 'x' && s[j ^ 1][i + 1] == 'x'){
            ans++;
        }
    }
}
cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
