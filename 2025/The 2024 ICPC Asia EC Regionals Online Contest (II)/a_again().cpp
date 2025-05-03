#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
typedef pair<array<int, 2>, string> PAS;
#define all(x) (x).begin(), (x).end()
void solve()
{
int n,k;
cin >> n >> k;
int q = INT_MAX;
for(int i = 0;i < k;i++){
    int c;
    cin >> c;
    q = min({c,q,n});
}

vector<pair<array<int,2>,string>> a;
for(int i = 0;i < n;i++){
    int x;
    string s;
    cin >> x >> s;
a.push_back ({{x,i},s});

}
vector<int> ans(n);
map<string,int> mp;
sort(all(a),greater<PAS>());
int cur = 0;
for(auto e : a){
    int l = e.first[1];
string s = e.second;
if(mp[s] < q){
    cur++;
    mp[s]++;
}
ans[l] = cur;
}

for(auto &e : ans){
    cout << e << nl;
    
}


}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
