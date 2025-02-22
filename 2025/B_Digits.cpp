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
int n,d;
cin >> n >> d;
n = min(n,6);
int m = 1;
for(int i = 1;i <= n;i++){
    m *= i;
}
for(int v = 1;v <= 9;v += 2){
    int x = 0;
    for(int i = 0;i < m;i++){
        x = (10 * x + d) % v;
    }
    if(x == 0){
        cout << v << " ";
    }
}
cout << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
