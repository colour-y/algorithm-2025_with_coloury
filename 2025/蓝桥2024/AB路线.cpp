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
int n,m,k;
cin >> n >> m >> k;
vector a(n,vector<int>(m)),f(n,vector<int>(m));
for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
        char c;
        cin >> c;
        if(c == 'A'){
            a[i][j] = 1;
        }else a[i][j] = 0;
    }
}

f[0][0] = 1;

for(int i = 0;i < n;i++){
    for(int j = 0 ;j < m;j++){
        auto& e = f[i][j];
if(i - 1 >= 0){
    if(a[i - 1][j] == a[i][j]) e = max(e,a[i - 1][j] + 1 );
    else e = max(e,1);
}
if(j - 1 >= 0){
    if(a[i][j] == a[i][j - 1]) e = max(e,a[i][j - 1] + 1 );
    else e = max(e,1);
}

        
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
