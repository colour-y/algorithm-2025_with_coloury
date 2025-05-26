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
string s;
cin >> s;
int a = 0,b = 0;
for(auto c : s){
    if(c == '1') a++;
    else b++;
}
if(b < a) swap(a,b);
int c = (b - a) / 2;
int d = a / 2 + b / 2;
if(k >= c && k <= d){
  if((k - c) % 2 == 1){
    cout << "no" << nl;
    
  }else{
    cout << "yes" << nl;
  }

}else{
    cout << "no" << nl;
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

