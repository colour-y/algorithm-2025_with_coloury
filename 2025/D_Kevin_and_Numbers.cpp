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
vector<ll> a(n),b(m);
map<ll,ll> mp;
for(int i = 0 ;i < n;i++){
    cin >> a[i];
    mp[a[i]]++;
}
for(int i = 0;i < m;i++){
    cin >> b[i];
}

ranges::sort(a);
ranges::sort(b);

auto dfs = [&](this auto&& dfs,ll k) -> bool{
    if(mp[k] > 0) mp[k]--;
    else if(k < a[0]) return false;
    else if(k == a[0] && mp[a[0]] == 0) return false;
    else{
        if(k % 2 == 1)
        {
            if(!dfs(k / 2 + 1)) return false;;
            if(!dfs(k / 2)) return false;
        }else{
            if(!dfs(k / 2)) return false;
            if(!dfs(k / 2)) return false;
        }
    }
  return true;
};
for(int i = m - 1;i >= 0;i--){
    if(!dfs(b[i])){
     cout << "NO" << nl;
     return;
     }
}
for(auto [x,y] : mp){
    if(y != 0){
        cout << "NO" << nl;
        return;
    }
}
cout << "YES" << nl;
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
