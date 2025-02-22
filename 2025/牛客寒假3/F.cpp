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
vector<int> a(3);
cin >> n ;
for(int i = 0;i < 3;i++){
    cin >> a[i];
}
if(accumulate(a.begin(),a.end(),0) < n){
    cout << "No" << nl;
    return; 
}
if(accumulate(a.begin(),a.end(),0) > n * 2 ){
    cout << "No" << nl;
    
}else cout << "Yes" << nl;
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
