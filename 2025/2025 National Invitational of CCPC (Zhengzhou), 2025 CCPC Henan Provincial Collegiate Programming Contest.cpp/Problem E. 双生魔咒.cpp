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
vector a(200010,vector<int>(26));
int p = 1;
vector<ll> cnt(200010);
string s;

auto init = [&]() -> void{
int t = 0,n = s.size(),i,x;
for(int i = 0;i < n;i++){
    x = s[i] - 'a';
    if(a[t][x] == 0){
        a[t][x] = p;
        p++;
    }
    t = a[t][x];
    cnt[t]++;
}
};

int n;
cin >> n;
ll ans = 0;
for(int i = 0;i < 2 * n;i++){
    cin >> s;
    init();

}

for(int i = 1;i < p;i++) ans += (cnt[i] / 2) * ((cnt[i] + 1) / 2);
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

