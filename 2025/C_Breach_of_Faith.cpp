#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n;
cin >> n;
vector<ll> a(2 * n);
for(auto &e : a){
    cin >> e;
}
ranges::sort(a);
ll k = 0;
for(int i  = 0;i < 2 * n;i++){
  if(i < n - 1) k -= a[i];
  else k += a[i]; 
}
cout << a[n - 1] << " " << k << " ";
for(int i=n,j=n-2;i<2*n;i++,j--){
  cout<<a[i]<<" ";
  if(j>=0) cout<<a[j]<<" ";
}
cout << nl;
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