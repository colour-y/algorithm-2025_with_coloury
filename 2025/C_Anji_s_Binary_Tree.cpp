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
string s;
cin >> s;
vector<int> l(n),r(n);
for(int i = 0;i < n;i++){
    cin >> l[i] >> r[i];
    l[i]--,r[i]--;
}
auto dfs = [&](auto self,int x) -> int{
    if (l[x] == -1 && r[x] == -1) {
        return 0;
    }
    int ans = n;
    if (l[x] != -1) {
        ans = self(self, l[x]) + (s[x] != 'L');
    }
    if (r[x] != -1) {
        ans = std::min(ans, self(self, r[x]) + (s[x] != 'R'));
    }
    return ans;
};
int ans = dfs(dfs,0);
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
