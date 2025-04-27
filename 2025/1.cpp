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
int n,m;
cin >> n >> m;
vector<vector<int>> a(m + 1,vector<int>(n + 1));
int k;
cin >> k;
int e;

cin >> e;
vector<array<int,2>> ans;

for(int i = 1;i <= m;i++){
    for(int j = 1;j <= n;j++){
cin >> a[i][j];
if(a[i][j] == k) {
    int x,y;
    if(i < m / 2) x = m / 2 - i - 1,x = -x;
    else  x = i  - m / 2 + 1;
if(j < n / 2) y = n / 2 - j - 1,y = -y;
   else 
    y = j  - n / 2 + 1;


    ans.push_back({y,x});
}

    }
}

sort(all(ans),[&](auto x,auto y){
int c = abs(x[0] - m / 2);
int d = abs(x[1] - n / 2);
int e = abs(y[0] - m / 2);
int f = abs(y[1] - n / 2);
int l = c < d;
int r = e < f;
if(l == r){
 if(c == e) return d < f;
 return c < e; 
}

return l < r;
});
for(int i = 0;i < e && i < ans.size();i++){
    cout << ans[i][0] << " " << ans[i][1] << " ";
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
