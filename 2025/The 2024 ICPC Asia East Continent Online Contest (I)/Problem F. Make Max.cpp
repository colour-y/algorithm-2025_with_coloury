#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

void solve()
{
  int n;
  cin >> n;

vector<ll> a(n);
vector<ll> alls;
vector<vector<ll>> b(n);
for(int i = 0;i < n;i++){
  cin >> a[i];
  alls.push_back(a[i]);
}

sort(all(alls));
unique(all(alls));

for(int i = 0;i < n;i++){
  a[i] = lower_bound(all(alls),a[i]) - alls.begin();
  b[a[i]].push_back(i);
}

vector<ll> lst(n), nxt(n);
vector<ll> stk;
for(int i = 0;i < n;i++){
  while(!stk.empty() && a[i] >= a[stk.back()]){
    stk.pop_back();
  }
  lst[i] = stk.empty() ? -1  : stk.back();
  stk.push_back(i);
}

stk.clear();
for(int i = n - 1;i >= 0;i--){
  while(!stk.empty() && a[i] >= a[stk.back()]){
    stk.pop_back();
  }
  nxt[i] = stk.empty() ? -1 : stk.back();
  stk.push_back(i);
}

vector<ll> ans(n);
for(int j = n - 1;j >= 0;j--)
{
  for(auto &i : b[j]){
    int fa;
    if(nxt[i] == -1 && lst[i] == -1)continue;
    if(nxt[i] == -1 ) fa = lst[i];
    else if(lst[i] == -1) fa = nxt[i];
    else if(a[nxt[i]] > a[lst[i]] ) fa = lst[i];
    else fa = nxt[i];
    ans[i] = ans[fa] + 1;
  }
}

ll res = 0;
for(int i = 0;i < n;i++){
  res += ans[i];
}
cout << res << nl;

}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}