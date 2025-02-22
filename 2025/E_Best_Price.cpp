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
cin  >> n >> k;
vector<ll> a(n),b(n);
for(int i = 0 ;i < n;i++){
cin >> a[i];

}
for(int i = 0 ;i < n;i++){
cin >> b[i];
}

vector<array<int,2>> e;
for(int i = 0 ;i < n;i++){
   e.push_back({a[i], 0});
   e.push_back({b[i], 1});
}
ranges::sort(e);

int cnt1 = n,cnt0  = 0;
ll ans = 0;
int lst = 0;
for(auto [x,i] : e){
    if(x > lst  && cnt0 <= k){
        ans = max(ans,1LL * x * (cnt0 + cnt1));

    }
    lst = x;
    if(i == 0){
        cnt1--;
        cnt0++;

    }else{
        cnt0--;
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
