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

vector<vector<int>> a(n,vector<int>(n));
a[0][0] = 1;
for(int i = 1;i < n;i++){
    for(int j = 0;j <= i;j++){
        if(j == 0) a[i][j] = a[i - 1][j];
        else if(j == i) a[i][j] = a[i - 1][j - 1];
        else{
            a[i][j] = a[i - 1][j - 1] ^ a[i - 1][j];
        }
    }
}

for(int i = 0;i < n;i++){
    for(int j = 0;j <= i;j++){
    cout << a[i][j] << " ";
    }
    cout << nl;
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
