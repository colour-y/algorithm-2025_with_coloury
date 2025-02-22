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
int n;
cin >> n;
vector<int> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
if(a[0] > a[1]){
    cout << "NO" << nl;
    return;
}
int k = 0;
a[1] -= a[0];
a[0] = 0;
k = a[1];
for(int i = 1;i < n - 1;i++){
    if(a[i] <= a[i + 1]){
       a[i + 1] -= a[i];
       a[i] = 0;   
    }else {

        cout << "NO" << nl;
        return;
    }
}

cout << "YES" << nl;
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
