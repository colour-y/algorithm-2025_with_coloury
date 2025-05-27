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
int n,m;
cin >> n >> m;
vector a(n,vector<int>(m));

for(int i = 0;i < n;i++)
{
    for(int j = 0 ;j < m;j++){
        cin >> a[i][j];
    }
}

vector<int> b(m,1);
for(int j = 0;j < m;j++){
    for(int i = 1;i < n;i++){
        if(a[i][j] == a[i - 1][j]) b[j]++;
        else break;
    }
}
map<int,int> mp;

for(int i = 0 ;i < m;i++){
    int k = a[0][i];
    mp[k] = max(mp[k],b[i]);
}
int ans = 0;
for(int i = 1;i <= m;i++){
ans += n - mp[i];
}
cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}

