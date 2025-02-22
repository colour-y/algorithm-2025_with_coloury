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
vector<int> a(n + 1),p(n + 1);
for(int i = 1;i <= n ;i++){
    cin >> a[i];
    p[a[i]] = i;
}
vector<vector<int>> q(n + 1);
vector<int> l(m),r(m),c(m),ans(m);
for(int i = 0;i < m;i++){
    cin >> l[i] >> r[i] >> c[i];
    q[a[c[i]]].push_back(i);
}
vector<int> bit(n + 1);
auto add = [&](int i){
    for(;i <= n ;i += i & -i) bit[i]++;
};
auto sum = [&](int i){
    int res = 0;
    for(;i;i -= i & -i) res += bit[i];
    return res;
};
for(int i = 1;i <= n;i++){
    for(int j : q[i]) ans[j] = sum(r[j]) - sum(l[j] - 1) + l[j];
    add(p[i]);
}

for(int i : ans) cout << i << nl;
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
