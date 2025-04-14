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
vector a(n,vector<int>(n) );
for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
        char c;
        cin >> c;
        if(c == '.') a[i][j] = 0;
        else a[i][j] = 1;
    }
}


auto dfs = [&](int i,int j) -> bool{

};


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
