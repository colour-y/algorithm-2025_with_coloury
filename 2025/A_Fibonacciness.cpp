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
int a,b,c,d;
cin >> a >> b >> c >> d;
int ans = 1,res = 1;
int k1  = a + b,k2 = d - c;
if(k1 == k2) ans++,res++;
if(k1 + b == c) ans++;
if(k2 + b == c) res++;
cout << max(ans,res) << nl;
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
