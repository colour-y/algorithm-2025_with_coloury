#include<bits/stdc++.h>
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
    vector<int> d(n);
    for(auto &e : d){
        cin >> e;
    }
  
vector<int> l(n + 1),r(n + 1);
bool ok = 1;
for(int i = 1;i <= n;i++){
    cin >> l[i] >> r[i];
    l[i] = max(l[i],l[i - 1] + (d[i - 1] == 1 ? 1 : 0));
    r[i] = min(r[i],r[i - 1] + (d[i - 1] == 0 ? 0 : 1));
    if(l[i] > r[i]){
        ok = 0;
    }
}

if(!ok){
    cout << -1 << nl;
    return;
}

int x = l[n];
for(int i = n - 1;i >= 0;i--){
    if(d[i] == -1){
        int nx = max(x - 1,l[i]);
        d[i] = x - nx;
    }
    x -= d[i];
}

for(int i = 0;i < n;i++)
{
    cout << d[i] << " ";
}
cout << nl;
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
