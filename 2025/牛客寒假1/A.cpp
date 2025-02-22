#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  bool isPrime(ll num) {
    if (num <= 3) {
        return num > 1;
    }
    // 不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    ll sqr = sqrt(num);
    for (int i = 5; i <= sqr; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}



void solve(){
int n;
cin >> n;
vector<ll> a(n);
ll ans = 2;
for(int i = 0 ;i  <n;i++){
    cin >> a[i];
}
ranges::sort(a);
if(a[0] == 1){
    cout << -1 << nl;
    return;
}
ll k = a[n - 1] + 1;
while(1){
    if(isPrime(k)){
        cout << k << nl;
        return;
    }else{
        k++;
    }
}
cout << -1 << nl;
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
