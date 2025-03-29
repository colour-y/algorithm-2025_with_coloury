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
int e;
cin >> e;
int res = INT_MAX;
int k = 0;
int ans = 0;
vector<int> a(n);
for(auto &r : a){
    cin >> r;

}

sort(all(a),greater());
for(int i = 0;i < n;i++){
    k++;
    res = min(res,a[i]);
    if(k * res >= e){
        ans++;
        k = 0;
        res = INT_MAX;
    }
}
cout << ans << nl;
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
