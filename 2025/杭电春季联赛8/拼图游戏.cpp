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
vector a(n,vector<int>(m));
for(int i = 0;i < n;i++){
    for(int j = 0; j < m;j++){
        cin >> a[i][j];
        a[i][j]--;
    }
}
vector b(n,vector<bitset<2000>>(m));
b[0][0].set(a[0][0]);
int ans = 0;
if(b[0][0].count() == k){
ans++;
}
for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
        if(i != 0){
            b[i][j] |= b[i - 1][j];
        }
        if(j != 0){
            b[i][j] |= b[i][j - 1];
        }
        b[i][j].set(a[i][j]);
        if(b[i][j].count() == k){
            ans++;
        }
    }
}
cout << ans << nl;
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
