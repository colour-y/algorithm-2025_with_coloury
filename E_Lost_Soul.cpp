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
vector<int> a(n),b(n);
for(auto &e : a){
    cin >> e;
}
for(auto &e : b){
    cin >> e;
}
int ans = 0;
vector<int> c,d;
for(int i = 0;i < n;i++){
    if(i % 2) c.push_back(a[i]);
    else c.push_back(b[i]);

    if(i % 2) d.push_back(b[i]);
    else d.push_back(a[i]);
}

map<int,int> mp,np;
for(int i = n - 1;i >= 0;i--){
    if(!mp[c[i]]) mp[c[i]] = i + 1;
if(!np[d[i]]) np[d[i]] = i + 1;
}

for(int i = n - 1;i >= 0;i--){
    if(mp[d[i]]) ans = max(ans,min(i + 1,mp[d[i]]));

}
// cout << ans << nl;

for(int i = n - 1;i >= 0;i--){
    if(mp[c[i]] != i + 1 && mp[c[i]] != 0 && mp[c[i]] != i + 2){
        ans = max(ans,i + 1);
    }
        if(np[d[i]] != i + 1 && np[d[i]] != 0 && np[d[i]] != i + 2){
        ans = max(ans,i + 1);
    }
}
// for(auto e : d){
//     cout << e << " " ;
// }
// cout << nl;
cout << ans << nl;
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

