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
int n,k;
cin >> n >> k;
vector<int> a(n);
for(auto &e : a){
    cin >> e;
}

auto check = [&](auto x){
vector<int> memo(x);
int cnt = 0;
int fix = 0;
for(int i = 0;i < n;i++){
    if(a[i] < x &&  !memo[a[i]]){
        memo[a[i]] = 1;
   cnt++;
    }
if(cnt == x){
    fill(all(memo),0);
    cnt = 0;
    fix++;
}
}

return fix >= k;

};


int lo = 0, hi = n;
while (lo < hi) {
    int x = (lo + hi + 1) / 2;
    if (check(x)) {
        lo = x;
    } else {
        hi = x - 1;
    }
}
cout << lo<< nl;
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
