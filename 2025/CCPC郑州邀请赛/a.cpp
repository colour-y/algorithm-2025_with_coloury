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
int k = to_string(n).size();
ll pw = 1;
for(int i = 0;i < k;i++){
    pw *= 10;
}

ll lo = pw * (1234567890 + d);
ll ro = (lo + n - 1) / n;
cout << ro << nl;

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
