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
int n,k;
cin >> n >> k;
vector<ll> a(n);
for(auto &e : a){
    cin >> e;
}

auto cph = [&](ll x) ->int{
ll m = 2;
ll res = 1;
while(1){
    if(x % m == 0) m *= 2,res++;
    else return res;
}
};

int l = n,r = 0;
for(int i = 0;i < n;i++){
    if(a[i] % 2 == 1) r++;
    else{
r += cph(a[i]);
    }
}
if(k >= l && k <= r){
    cout << "yes" << nl;
}else{
    cout << "no" << nl;
}
cout << l << " " << r << nl;
cout << cph(96) << nl;
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

