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
int n;
cin >> n;
vector<ll> a(n);
int ok = 0;
map<ll,int> mp;
for(auto &e : a){
    cin >> e;
    mp[e]++;
    if(mp[e] >= 4) ok = 1;
}
if(ok){
    cout << "Yes" << nl;
    return;
}

ranges::sort(a);

a.erase(unique(all(a)),a.end());
int k = 0;
for(int i = 1;i < a.size();i++){
    if(a[i] == a[i - 1] + 1){
        int x = mp[a[i - 1]];
        int y = mp[a[i]];
if(x >= 2 && y >= 2){
    cout << "Yes" << nl;
    return;
}else if(x >= 2 && y == 1) k = 2;
else if(k == 2 && y >= 2){
    cout << "Yes" << nl;
    return;
}
    }else k = 0;
}
cout << "No" << nl;
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
