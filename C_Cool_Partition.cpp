#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve() {
 int n;
 cin >> n;
 vector<int> a(n);
 for(auto &e : a)
 {
    cin >> e;
 }

 set<int> b,c;
 int ans = 1;
 c.insert(a[0]);
 for(int i = 1;i < n;i++){
    b.insert(a[i]);
    c.insert(a[i]);
    if(b.size() == c.size()){
        ans++;
        b.clear();
    }

 }
 cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
