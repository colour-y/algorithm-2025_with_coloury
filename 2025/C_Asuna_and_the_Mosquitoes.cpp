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
vector<ll> a(n);
ll k1 = 0,k2 = 0;
for(auto &e : a)
{
    cin >> e;
}
ll mx1 = 0,mx2 = 0;
int k = 0;
ranges::sort(a);
for(int i = 0 ;i < n;i++){
    if(a[i] % 2 == 1){
        k1 += a[i];
        k++;
    }else {
        k2 += a[i];
        
    }
}

if(k1 == 0 || k2 == 0){
    cout << a[n - 1] << nl;
    return;
}
cout << k2 + k1 - k + 1 << nl;
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
