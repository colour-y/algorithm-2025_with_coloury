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
    std::string s, n;
int k, f[28], cnt[28];
    std::cin >> s >> n;
    if (n.size() > 4) k = 27; else k = std::stoi(n);
    for (int x = 0; x < 26; x++) f[x] = 0, cnt[x] = 0;
    for (auto c : s) cnt[c - 'a']++;
    for (int t = std::min(k, 27); t; t--) {
        for (auto c : s) {
            int j = c - 'a';
            f[j] = std::max(f[j], 1);
            for (int i = j - 1; i >= 0; i--)
                f[j] = std::max(f[j], f[i] + 1);
        }
    }
    std::cout << *std::max_element(f, f + 26) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}