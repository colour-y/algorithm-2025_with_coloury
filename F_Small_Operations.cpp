#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

constexpr int inf = 1e9 + 7;

int get(int x,int k){
  vector<int> divs;
  for(int i = 1;i * i <= x;i++){
    if(x % i == 0){
      divs.push_back(i);
      if(i * i < x){
        divs.push_back(x / i);
      }
    }
  }
ranges::sort(divs);

int d = divs.size();
vector<int> dp(d,inf);
dp[0] = 0;
for(int i = 1;i < d;i++){
  for(int j = 0;j < i;j++){
    if(divs[i] % divs[j] == 0 && divs[i] / divs[j] <= k){
      dp[i] = min(dp[i],dp[j] + 1);
    }
  }
}
return dp[d - 1];


}


void solve()
{
int x,y,k;
cin >> x >> y >> k;

int g = gcd(x,y);
int ans = get(x / g,k) + get(y / g,k);
if(ans >= inf) ans = -1;
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

