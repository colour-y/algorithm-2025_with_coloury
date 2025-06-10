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
int n;
cin >> n;
vector<int> a(n);
for(auto &e : a)
{
    cin >> e;
}

if(count(all(a),1) == n){
     cout << "YES" << nl;
        return;
} 



for(int i = 1;i < n;i++){
    if(a[i - 1] == 0 && a[i] == 0){
        cout << "YES" << nl;
        return;
    }
}

     cout << "NO" << nl;
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

