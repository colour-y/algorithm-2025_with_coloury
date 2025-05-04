#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n,m;
cin >> n >> m;
string s,c;
cin >> s >> c;
vector<int> a;
for(int i = 0;i <m - n + 1;i++){
    a.push_back(i);
}
// for(auto e : a){
//     cout << e << nl;
// }
int ans =0 ;
sort(all(a),[&](int u,int v){
    for (int i = 0; i < n; i++)
    if (c[u + i] != c[v + i]) {
        if ((s[i] ^ c[u + i]) > (s[i] ^ c[v + i]))
            return true;
        else
            return false;
    }
return u > v;
});

for(int i = 0;i < n;i++){
    if(s[i] != c[a[0] + i] ) ans++;

}
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
