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
        int n, m;
        cin >> n >> m;
        vector a(n,vector<int>(m));
        for(int i = 0 ;i < n;i++){
            for(int j = 0;j < m;j++){
                cin >> a[i][j];
            }
        }
for(int i = 0;i < n;i++){
    ranges::sort(a[i]);
}
vector<int> ans(n);
vector<int> res;
for(int i = 0;i < n;i++){
    res.push_back(a[i][0]);
}
 res.erase(unique(res.begin(), res.end()), res.end());
 if(res.size() != n){
    cout << -1 << nl;
    return;
 }
iota(ans.begin(),ans.end(),0);
sort(ans.begin(),ans.end(),[&](auto &x,auto &y){
return res[x] < res[y];
});
ranges::sort(res);
int d = res[n - 1];
for(int i = 1;i < m;i++){
    for(int j = 0;j < n;j++){
if(a[ans[j]][i] <= d){
    cout << -1 << nl;
    return;
}
d = a[ans[j]][i];
    }
}
for(int i = 0 ;i < n;i++){
    cout << ans[i] + 1 << " ";
}
cout << nl;
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
