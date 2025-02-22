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
int n,m,k;
cin >> n >> m >> k;
vector<ll> a(n),b(m);
for(int i  = 0 ;i < n;i++){
    cin >> a[i];
}
for(int i = 0;i < m ;i++){
    cin >> b[i];
}
map<int,int> cnt;
for(int i = 0;i < m;i++){
    cnt[b[i]]++;
}
int ans = 0;
int good = 0;
for(int i = 0;i < m - 1;i++){
    good += cnt[a[i]]-- > 0;
}
for(int i = 0 ;i <= n - m;i++)
{
    good += cnt[a[i + m - 1]]-- > 0;
    ans += (good >= k);
    good -= ++cnt[a[i]] > 0;
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
