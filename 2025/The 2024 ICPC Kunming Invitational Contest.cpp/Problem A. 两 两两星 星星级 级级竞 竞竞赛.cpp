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
ll k;
cin >> n >> m >> k;
vector<int> p(n);
iota(all(p),0);
vector<ll> a(n);
vector<array<ll,2>> sum(n);
vector b(n,vector<ll>(m));
for(int i = 0;i < n;i++){
    cin >> a[i];
    for(int j = 0;j < m;j++){
cin >> b[i][j];
if(b[i][j] != 0){
    sum[i][0] += b[i][j];
}else{
    sum[i][1]++;
}
    }
}

sort(all(p),[&](auto x,auto y){
if(a[x] == a[y]) return sum[x][0] > sum[y][0];
return a[x] < a[y];
});

for(int i = 0;i < n;i++){
if(i == 0){

}
}
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
