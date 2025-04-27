#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()


int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};

void solve(){
int n;
cin >> n;
string s;
cin >> s;
ll ans = 0;
array<vector<ll>,2> a{vector<ll>(n + 1,0LL),vector<ll>(n + 1,0LL)};
for(int i = 0 ;i < n;i++){
if(s[i] == '0'){
    a[0][i + 1] = a[0][i] + i;
    a[1][i + 1] = a[1][i] + n - i - 1;
ans = max(ans,a[0][i + 1]);
ans = max(ans,a[1][i + 1]);
} else{
    a[0][i + 1] = a[1][i] + 1;
    a[1][i + 1] = 0;
    ans = max(ans,a[0][i + 1]);
ans = max(ans,a[1][i + 1]);
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
