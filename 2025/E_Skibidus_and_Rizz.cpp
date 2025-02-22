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
if(abs(n - m) > k || max(n,m) < k){
    cout << -1 << nl;
    return;
}
int t = 0;
if(n < m){
    swap(n,m);
    t = 1;
}
string s;
while(n > 0 || m > 0){
    for(int i = 0;i < k && n ;i++){
        n--;
        s += '0' ^ t;
    }
    for(int i = 0;i < k && m;i++){
        m--;
        s += '1' ^ t;
    }
}
cout << s << nl;
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
