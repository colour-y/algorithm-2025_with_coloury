#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
 

    int ans = 0;
    set<int> vis;
    vis.emplace(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        if (vis.contains(a[i])) {
            vis.clear();
            ans++;
        }
        vis.emplace(a[i]);
    }
    cout << ans << "\n";
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
