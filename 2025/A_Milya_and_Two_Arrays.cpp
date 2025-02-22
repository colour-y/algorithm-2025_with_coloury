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
cin >> n ;
vector<int> a(n),b(n);
map<int,int> mpa,mpb;
int k1 = 0,k2 = 0;
for(int i = 0;i < n;i++){
    cin >> a[i];
    if(!mpa[a[i]]) k1++;
    mpa[a[i]]++;

}
for(int i = 0;i < n;i++){
    cin >> b[i];
    if(!mpb[b[i]]) k2++;
    mpb[b[i]]++;
}
if(k1  * k2 >= 3){
    cout << "YES" << nl;
}else{
    cout << "NO" << nl;
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
