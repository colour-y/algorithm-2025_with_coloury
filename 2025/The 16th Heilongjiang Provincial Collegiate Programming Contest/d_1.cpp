#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
const int mod = 1000003;
auto pow(int x){
return x * x % mod;    
}

void solve(){
int n;
cin >> n;
vector<int> a(n);
for(auto &e : a){
    cin >> e;
}

ll res = 0;
auto cph = [&](int x) -> ll{
ll ans = 0;
ll k = a[x];
int i = x - 1,j = x + 1;
while(i >= 0 || j < n){
    if(i < 0){
        ans += pow(k - a[j]) % mod;
        k *= a[j];
    j++;
    }else if(j == n){
        ans += pow(k - a[i]) % mod;
        k *= a[i];
        i--;
    }
    else{
        if(a[i] >= a[j]){
            ans += pow(k - a[i]) % mod;
            k *= a[i];
            i--;
        }else{
            ans += pow(k - a[j]) % mod;
            k *= a[j];
        j++;
        }
    }
k %= mod;
}

return ans;
};

for(int i = 0;i < n;i++){
  
    res = max(res,cph(i));
    res %= mod;
}
cout << res % mod << nl;

}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}
