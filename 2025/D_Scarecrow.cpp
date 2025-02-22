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
int n,k,l;
cin >> n >> k >> l;
k *= 2;
l *= 2;

vector<int> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
    a[i] *= 2;
}
int ans = a[0];
int x = k;
for(int i = 1;i < n;i++){
    if(a[i] > x){
        a[i] = max(x,a[i] - ans);
        assert((a[i] - x) % 2 == 0);
        ans += (a[i] - x) / 2;
        x = (x + a[i]) / 2 + k;
    }else{
        a[i] = min(x,a[i] + ans);
        assert(x <= a[i] + k);
        x = a[i] + k;
    }
}

if(x < l){
    ans += l - x;
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
