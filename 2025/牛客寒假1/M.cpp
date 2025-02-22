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
int n ;
cin >> n;
vector<ll> a(n);
int k = 0;
for(int i = 0;i < n;i++){
    cin >> a[i];
    if(a[i] < a[k]){
        k = i;
    }
}
a[k] *= 2;
ll mx = *max_element(a.begin(),a.end());
ll mi = *min_element(a.begin(),a.end());
cout << mx - mi << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
