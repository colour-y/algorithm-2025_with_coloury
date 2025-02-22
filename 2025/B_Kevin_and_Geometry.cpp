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
vector<ll> a(n);
map<ll,ll> mp;
for(int i = 0;i < n;i++){
    cin >> a[i];
    mp[a[i]]++;
}
vector<ll> ans;
ll res = -1;
for(auto [x,y] : mp){
if(y >= 2){
    res = x;
}
}
if(res == -1){
    cout << -1 << nl;
    return;
}
vector<ll> b;
int k = 2;
for(int i = 0;i < n;i++){
    if(a[i] != res || k == 0){
        b.push_back(a[i]);
    } else if(k > 0 && a[i] == res){
        k--;
    }
}
ans.push_back(res);
ans.push_back(res);
ranges::sort(b);
vector<ll> c(n - 2);
res = 1e9;
int d = 0;
for(int i = 0;i < n - 3;i++){
    c[i] = b[i + 1] - b[i];
if(c[i] < res){
    res = c[i];
d = i;
}

}
ans.push_back(b[d]);
ans.push_back(b[d + 1]);
ranges::sort(ans);
if(ans[0] + ans[1] + ans[2] <= ans[3]){
    cout << -1 << nl;
}else{
    for(int i = 0;i < 4;i++){
        cout << ans[i] << " ";
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
