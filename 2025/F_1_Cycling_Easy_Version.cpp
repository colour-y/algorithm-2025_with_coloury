#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  using T = tuple<ll, int, vector<int>>; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        set<pair<int, vector<int>>> ok;
        priority_queue<T, vector<T>, greater<>> pq;
        pq.emplace(0, n, a); 

        while (!pq.empty()) {
            auto [c, d, e] = pq.top();
            pq.pop();

            if (d == 0) {
                cout << c << nl;
                break;
            }

            if (!ok.insert({d, e}).second) continue;

    
            pq.emplace(c + e[d - 1], d - 1, e);

     
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j) {
                    auto b = e;
                    swap(b[i], b[j]);
                    if (ok.count({d, b})) continue;
                    pq.emplace(c + (j - i), d, b);
                }
        }
    }
    return 0;
}
