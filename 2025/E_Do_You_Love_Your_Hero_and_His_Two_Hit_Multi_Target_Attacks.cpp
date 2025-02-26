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
int k;
cin >> k;
if(k == 0){
    cout << 2 << nl;
    cout << 2 << " " << 2 << nl;
    cout << 3 << " " << 3 << nl;
    return;
}
int res = 0;
vector<array<int,2>> ans;
int x = 0,y = 0;
while(k)
{
    int n = 2;

while(n * (n - 1) / 2 <= k){
    n++;
}

n--;

for(int i = 0;i < n;i++){
    ans.push_back({x++,y});
}
k -= n * (n - 1) / 2;
res += n;
x++,y++;
}



cout << res << nl;
for(int i = 0;i < ans.size();i++){
    cout << ans[i][0] << " " << ans[i][1] << nl;
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
