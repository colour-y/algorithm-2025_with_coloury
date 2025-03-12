#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

 vector<int> light(101);
 int n = 4;
  void press(int x)
  {
      light[x]^=1;
      for (int y=x+x;y<=n;y+=x) press(y);
  }



void solve(){
    
    for (int i=1;i<=n;i++) {press(i);
        for(int i = 1;i <= n;i++)
{
    cout << light[i] << " ";
}
cout << nl;
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
