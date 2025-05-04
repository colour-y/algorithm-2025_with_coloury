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
int a,b,c;
cin >> n >> a >> b >> c ;
vector<array<int,2>> e(n);
for(int i = 0 ;i < n;i++){
cin >> e[i][0] >> e[i][1];
}

int d;
cin >> d;

int ans = 0;
for(auto [x,y] : e){
    if(x + d <= a && x + y < c && x + y + d >= c ) ans++;
    else if(x + d > a && a + y >= c && x + y < c)  ans++;

}
cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
