#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n;
cin >> n;
vector<int> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}

ranges::sort(a);

int h = n / 2;
int ml = a[h / 2],mr = a[h + h / 2];
ll ans = 1e18;

for(auto xl : {ml,ml - 1}){
    for(auto xr : {mr,mr + 1}){
        if(xl == xr){
            continue;
        }

        ll res =  0;
        for(int i = 0;i < h;i++){
            res += abs(a[i] - xl);
            res += abs(a[h + i] - xr);
        }
        ans = min(ans,res);
    }
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
