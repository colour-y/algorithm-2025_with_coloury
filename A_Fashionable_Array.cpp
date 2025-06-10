#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve()
{
int n;
cin >> n;
vector<int> a(n);
for(auto &e : a){
    cin >> e;
}

ranges::sort(a);
if((a[0] + a[n - 1]) % 2 == 0){
    cout << 0 << nl;
    return;
}

int ans = INT_MAX;
int res = 0;
for(int i = 0;i < n - 1;i++){
    if((a[i] + a[n - 1] ) % 2 == 0){
    break;
    }else res++;
}
ans = min(ans,res);

res = 0;
for(int i = n - 1;i > 0;i--){
if((a[i] + a[0]) % 2 == 0){
    break;
}else{
    res++;
}
}

ans = min(ans,res);
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

