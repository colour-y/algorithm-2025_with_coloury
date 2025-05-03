#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  #define int long long
void solve(){
//解决示例具体方法
int n,c,d,e,f;
cin >> n >> c >> d >> e >> f;
int ans = 0;
for(int i = 1;i < 10007;i++){
    int t = i * i * i * c + i * i * d + i * e + f;
    vector<int> kt;
    while(t){
        kt.push_back({t % 27});
        t /= 27;
    }

    if((int)kt.size() > n) continue;
    bool ok = 0;
    for(auto x : kt){
        if(x == 0){
            ok = 1;
            break;
        }

    }
    if(ok) continue;
    int m = 1,s = 0;
    for(auto x : kt){
        s += x * m;
        s %= 10007;
        m = m * 10 % 10007;
    }

if(s == i) ans++;

}
cout << ans << nl;
}


signed main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
