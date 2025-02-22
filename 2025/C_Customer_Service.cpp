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
cin >> n;
vector<vector<ll>> a(n,vector<ll>(n));
for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++)
    cin >> a[i][j];
}
    for (int i = 0; i < n; i++) {
        std::reverse(a[i].begin(), a[i].end());
        int s = 0;
        for (int j = 0; j < n; j++) {
            int v = a[i][j];
            a[i][j] = s;
            s = std::min(n, s + v);
        }
    }
    int ans = n;
    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (a[i][j] == j);
        }
        ans = std::min(ans, cnt + j);
    }
    
    std::cout << ans << "\n";
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
