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
 int n ;
 cin >> n;
 vector<int> a(n - 2);
 int k = 0;
 int ok = 1;
int kk = 0;
 for(int i = 0;i < n - 2;i++){
    cin >> a[i];
    if(a[i] == 1){
        kk = 1;
    }
    if(kk){
        
    if(a[i] == 0)k++;
    else if(k == 1){
        ok = 0;
    }else k = 0;
  
}
 }
if(ok) cout << "YES" << nl;
else cout << "NO" << nl;

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
