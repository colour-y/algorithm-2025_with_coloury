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
int n,m,k;
cin >> n >> m >> k;
if((k / n + (k % n >= 1) ) >= m){
    cout << m << nl;
    return;
}

int ans = k / n + (k % n>= 1);
int res = 1;
while(m > ans){
    m--;
res++;
}
int as = ans / 2 + (ans % 2 > 0);
ans =  ans / res + (ans % res > 0);
cout << min(ans,as) << nl;
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
