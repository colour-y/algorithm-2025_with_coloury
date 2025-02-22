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
for(auto &i : a)
{
    cin >> i;
}
vector<ll> pi(n),pk(n);
if(a[0] > 0){
    pi[0] = a[0];
}
for(int i = 1;i < n;i++){
    pi[i] = pi[i - 1];
    if(a[i] > 0){
        pi[i] += a[i];
    }
}

if(a[n - 1] < 0){
    pk[n - 1] = abs(a[n - 1]);
}
for(int i = n - 2;i >= 0;i--){
pk[i] = pk[i + 1];
if(a[i] < 0){
    pk[i] += abs(a[i]);
}
}
ll ans = 0;
for(int i  = 0;i < n;i++){
ans = max(ans,pi[i] + pk[i]);
}
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
