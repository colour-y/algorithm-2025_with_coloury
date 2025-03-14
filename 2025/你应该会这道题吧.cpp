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
vector a(n,vector<char>(n));
for(int i = 0 ;i < n;i++){
    for(int j =0 ;j < n;j++){
        cin >> a[i][j];
    }
}
int ans = 0;

for(int i = 0;i < n - 1;i++){
    if(i > n - 1 - i) break; 
    for(int j = i;j < n - 1 - i;j++){
        
int k1 = 0,k2 = 0;
if(a[i][j] == '0'){
    k1++;
}else k2++;

int x = n - i - 1,y = n - j - 1;

if(a[j][x] == '0'){
    k1++;
}else k2++;

if(a[y][i] == '0'){
    k1++;
}else k2++;

if(a[x][y] == '0'){
    k1++;
}else k2++;

ans += min(k1,k2);


    }
}

cout << ans << nl;
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

//12341
//41212
//32123
//21214
//14321