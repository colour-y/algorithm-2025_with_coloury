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
int n,k;
cin >> n >> k;
vector<ll> a(n);
map<ll,ll> cnt;
for(int i = 0;i < n;i++){
    cin >> a[i];
cnt[a[i]]++;
}
vector<ll> c;
for(auto [_,x] : cnt){
    c.push_back(x);
}
ranges::sort(c);
int ans = c.size();
for(int i = 0;i < c.size() - 1;i++){
    if(k >= c[i]){
        ans--;
        k -= c[i];
    }
}
cout << ans << nl;


}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
