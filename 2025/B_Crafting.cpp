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
vector<ll> a(n),b(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}
for(int i = 0;i < n;i++){
    cin >> b[i];
a[i] -= b[i];
}
ranges::sort(a);
int k = 0;
if(n == 1){
if(a[0] >= 0){
    cout << "yes" << nl;
}else{
    cout << "no" << nl;
}
return;
}

if(a[0] < 0 && a[1] < 0){
    cout << "no" << nl;
    return;
}

if(a[1] + a[0] < 0){
    cout << "no" << nl;
    return;
}
cout << "yes" << nl;


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
