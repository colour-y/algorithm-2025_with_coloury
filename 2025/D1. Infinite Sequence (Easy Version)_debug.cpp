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
    int l;
    cin >> n >> l >> l;
    vector<int> a(n);
    for(auto &k : a){
        cin >> k;
    }
    if(n == 1){
        cout << a[0] << nl;
        return;
    }
    
    
    vector<int> b(n);
    b[0] = a[0];
    for(int i = 1;i < n;i++){
        b[i] = a[i] ^ a[i - 1];
    }
    for(int i = n;i < l;i++){
        a[i] = b[i / 2];
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
