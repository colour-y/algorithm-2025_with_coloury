#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

vector<ll> manacher(vector<ll> s)
{
    vector<int> t{0};
    for(auto c:s){
        t.push_back(c);
        t.push_back(0);
    }
    int n = t.size();
    vector<ll> r(n);
    for (int i = 0, j = 0; i < n; i++)
    {
        if (2 * j - i >= 0 && j + r[j] > i)
        {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] - 1 >= 0 && i + r[i] + 1 < n && t[i - r[i] - 1] == t[i + r[i] + 1])
        {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j])
        {
            j = i;
        }
    }
    return r;
}
void solve()
{

    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &e : a){
        cin >> e;
    }

if(n == 1){
    cout << 1 << nl;
    return;
}


    vector<ll> d(n - 1);
    for(int i = 0;i < n - 1;i++){
        d[i] = a[i + 1] - a[i];
    }

    auto e = manacher(d);
    ll ans = n;
for(auto c : e){
    ans += (c + 1) / 2;
}
cout << ans << nl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
