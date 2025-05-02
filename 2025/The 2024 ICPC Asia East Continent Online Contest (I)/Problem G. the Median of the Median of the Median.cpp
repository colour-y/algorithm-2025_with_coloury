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
for(int i = 0;i < n;i++){
    cin >> a[i];
}

auto check = [&](int x){
vector<int> b(n + 1);
for(int i = 1;i <= n;i++)
{
    int k = a[i - 1] <= x ? 1 : -1;
    b[i] = b[i - 1] + k;
}
vector c(n + 1,vector<int>(n + 1)),d(n + 1,vector<int>(n + 1));

for(int i = 1;i <= n;i++){
    for(int j = i;j <= n;j++){
c[i][j] = b[j] - b[i - 1] >= 0 ? 1 : -1;
    }
}

for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
        d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + c[i][j];
    }
}

int res = 0;
for(int i = 1;i <= n;i++){
    for(int j = i;j <= n;j++){
        int k = (d[j][j] - d[i - 1][j] - d[j][i - 1] + d[i - 1][i - 1] >= 0 ? 1 : -1);
   res += k;
    }
}
return res >= 0;
};

int l = 0,r = 1e9 + 7;
while(l <= r){
    int mid = l + r >> 1;
    if(check(mid) ) r = mid - 1;
    else l = mid + 1;
}
cout << l << nl;

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
