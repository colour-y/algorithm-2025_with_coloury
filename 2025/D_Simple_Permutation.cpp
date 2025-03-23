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
    vector<int> res;
    if (n >= 1) res.push_back(2);
    if (n >= 2) res.push_back(1);
    if (n >= 3) res.push_back(3);
    for (int i = 4; i <= n; ++i) {
        res.push_back(i);
    }
    for (int i = 0; i < res.size(); ++i) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
ll sum = 0;
int k = 0;
for(int i = 0;i < n;i++){
sum += res[i];
int ans = sum / (i + 1);
if((i + 1) % 2 == 1){
    if(sum % (i + 1) >= (i + 1) / 2 + 1){
        ans++;
    }

}else if(sum % (i + 1) >= (i + 1) / 2){
ans++;
}
if(isPrime(ans)) k++;
if((k < n / 3 - 1) ) cout << k << " " << i + 1 << nl;
}

    

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
