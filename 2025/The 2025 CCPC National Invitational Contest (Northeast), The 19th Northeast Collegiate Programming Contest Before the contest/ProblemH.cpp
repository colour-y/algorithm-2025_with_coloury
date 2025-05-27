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
vector<int> a(n),b(n),c(n);
for(auto &e : a){
    
    cin >> e;
e--;
}

for(int i = 0;i < n;i++){
int x;
cin >> x;
b[a[i]] = x;

}

for(auto &e : c){
    cin >> e;
}

ll su = reduce(all(b),0LL);
auto check = [&](ll x) -> bool{
ll res = 0;
vector<ll> p(n);
ll k = 0;
    for(int i = 0;i < n;i++){
ll s = x / c[i];
        res += s;
p[i] = s;
k += s;
    }

if(k < su) return false;
for(int i = 0 ;i < n;i++){
    if(k - p[i] < b[i]) return false;
}

    if(res >= su){
        return true;
    }else{
        return false;
    }
};


ll l = 1,r =  1e12;
while(l < r){
    ll mid = (l + r) / 2;
if(check(mid) ) r = mid;
else l = mid + 1;
}
cout << l << nl;

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

