/*
    @file             6.cpp
    @author           1
    @date             2025-04-04 18:40
*/
#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define All(a) a.begin() + 1, a.end()
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define yes "Yes"
#define no "No"
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;
constexpr int MX = 2e9;
constexpr ll MAX = 2e18;


void solve() {
    ll d, r, x, y;
    cin >> d >> r >> x >> y;
    x = abs(x), y = abs(y);
    if (y <= d)
        cout << abs(x - r) << endl;
    else
        cout << lround(abs(sqrt((ld) x * x + (ld) (y - d) * (y - d)) - (ld) r)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}