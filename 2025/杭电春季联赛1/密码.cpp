#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  const vector<array<int, 3>> b = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

void solve(){
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    map<ll, int> cnt;
 
    for (auto& t : a) {
        set<ll> st;
        for (auto& p : b) {
            int a = t[p[0]];
            int b = t[p[1]];
            int c = t[p[2]];
            ll num = (ll)c - b;
            if (num % a != 0) continue;
            ll x = num / a;
            if (x >= 0) {
                st.insert(x);
            }
        }
        for (auto x : st) {
            cnt[x]++;
        }
    }
    for (auto& [x, c] : cnt) {
        if (c == n) {
            cout << x << '\n';
            break;
        }
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
