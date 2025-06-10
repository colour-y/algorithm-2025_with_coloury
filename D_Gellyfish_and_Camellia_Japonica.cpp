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
int n,q;
cin >> n >> q;
vector<ll> b(n);
for(auto &e : b)
{
    cin >> e;
}

vector<array<int,3>> ops(q);
for(auto &[x,y,z] : ops){
    cin >> x >> y  >> z;
x--,y--,z--;
}
ranges::reverse(ops);
vector<ll> a(b);
for(auto [x,y,z] : ops){
    a[x] = max(a[x],a[z]);
    a[y] = max(a[y],a[z]);
    if(z != y && z != x) a[z] = 0;

}

vector<ll> tmap(a);
ranges::reverse(ops);
for(auto [x,y,z] : ops){
    tmap[z] = min(tmap[x],tmap[y]);
}

if(tmap != b){
    cout << -1;
}else{
    for(auto x : a){
        cout << x << " ";
    }

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

