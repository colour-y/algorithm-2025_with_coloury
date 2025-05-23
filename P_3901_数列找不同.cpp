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
vector<int> a(n + 1),vis(n + 1);
for(int i = 1;i <= n;i++){
int e;
cin >> e;
vis[i] = max(vis[i - 1],a[e] + 1);
a[e] = i;
}

for(int i = 0;i < k;i++){
    int x,y;
    cin >> x >> y;
if(x < vis[y]){
    cout << "No" << nl;
    
}else{
    cout << "Yes" << nl;
}
}

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
