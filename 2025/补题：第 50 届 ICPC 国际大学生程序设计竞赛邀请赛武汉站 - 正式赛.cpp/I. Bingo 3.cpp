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
if(n == 1 && k == 1){
    cout << "Yes" << nl;
    cout << 1 << nl;
    return;
}

if(n - 1 >= k || k >  n * n - n + 1) {
    cout << "No" << nl;
    return;

}
cout << "Yes" << nl;
vector<vector<int>> a(n,vector<int>(n));
vector<int> vis(n * n + 1,0);
a[0][0] = k;
vis[k] = 1;
for(int i = 1;i < n;i++){
    a[0][i] = i;
    a[i][i] = k + i;
    vis[i] = 1;
    vis[k + i] = 1;
}
int kt = n;


for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
if(!a[i][j]){
while(vis[kt]){
    kt++;
}
cout << kt << " ";
kt++;
}else{
    cout << a[i][j] << " ";
}
    }
    cout << nl;
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
