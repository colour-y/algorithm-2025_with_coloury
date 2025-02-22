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
vector<int> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
int m = *max_element(a.begin(),a.end());
vector<int> cnt(m + 1);
for(auto x : a){
    cnt[x]++;
}
ll ans = 0;
for(int g = 1;g <= m;g++){
    for(int i = g;i <= m;i += g){
        int j = i ^ g;
        if(i < j && gcd(i,j) == g && j <= m){
            ans += 1LL * cnt[i] * cnt[j];
        }
    }
}
cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
