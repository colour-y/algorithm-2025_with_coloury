#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
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
int p = max(1,n / 3);
while(!isPrime(p)) p++;

int l = p,r = p;
vector<int> a;
a.push_back(p);
while(l > 1 && r < n){
    l--,r++;
    a.push_back(l);
    a.push_back(r);
}
for(int i = 1;i < l;i++) a.push_back(i);
for(int i = r + 1;i <= n;i++) a.push_back(i);
for(auto e : a){
    cout << e << " ";
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
