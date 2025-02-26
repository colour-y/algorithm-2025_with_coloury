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
vector<double> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
map<int,int> mp;
int x,y;
double ans = 0.00;
while(cin >> x >> y){
    if(x == 0 && y == 0) break;
x--;
mp[x] += y;
ans += y * a[x];
}
for(int i = 0;i < n;i++){
    cout << mp[i] << nl;
}
cout << fixed << setprecision(2)<< ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
