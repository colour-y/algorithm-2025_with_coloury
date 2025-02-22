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
int n,m;
cin >> n >> m;
vector a(n,vector<int>(m));
vector<int> f(n * m);
for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
        cin >> a[i][j];
        a[i][j]--;
        f[a[i][j]] = max(f[a[i][j]],1);
        if((i && a[i][j] == a[i - 1][j]) || (j && a[i][j] == a[i][j - 1]))
    f[a[i][j]] = 2;
    }
}
int ans = accumulate(f.begin(),f.end(),0) - *max_element(f.begin(),f.end());
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
