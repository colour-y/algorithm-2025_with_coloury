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
cin >> n ;
vector<int> a(n + 1),b(n + 1);
for(int i = 1;i <= n;i++) cin >> a[i];
for(int  i = 1;i <= n;i++) cin >> b[i];
vector<int> aa(n + 1),bb(n + 1);
for(int i = 1;i <= n;i++){
    aa[a[i]] = i;
    bb[b[i]] = i;
}

auto swp = [&](int x,int y){
    swap(a[x],a[y]),swap(b[x],b[y]);
    swap(aa[a[x]],aa[a[y]]),swap(bb[b[x]],bb[b[y]]);
};


vector<pair<int,int>> ans;
if(n % 2)
for(int i = 1;i <= n;i++){
    if(a[i] == b[i] && i != n / 2 + 1){
        ans.push_back({i,n / 2 + 1});
        swp(i,n / 2 + 1);
        break;
    }
}

for(int i = 1;i <= n ;i++){
    if(a[i] != b[n - i + 1]){
        ans.push_back({i,aa[b[n - i + 1]]});
        swp(i,aa[b[n - i + 1]]);
    }
}


for(int i = 1;i <= n;i++){
    if(a[i] != b[n - i + 1]){
        cout << -1 << nl;
        return;
    }
}

cout << ans.size() << nl;
for(int i = 0;i < ans.size() ;i++){
    cout << ans[i].first << ' ' << ans[i].second << nl;
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
