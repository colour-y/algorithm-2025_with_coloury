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
vector<int> a(n);
map<int,int> mp;
for(auto &e : a){
    cin >> e;
    mp[e]++;
}
int k = 0;
int r = 0;
for(auto [x,y] : mp){
    if(y >= 2){
        k += y - 2;
    }
    else if(y == 1){
r++;
    }
}

int ans = 0;
if(k >= r){
   ans = k;
}
else{
  ans += k;
    r -= k;
    ans += r / 2;
}
cout << ans << nl;
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
