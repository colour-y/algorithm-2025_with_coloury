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
cin >> n;
vector<int> a(2 * n + 1);
for(int i = 1;i <= 2 * n;i++){
   cin >> a[i];
}
a.push_back(-1);
if(n == 1){
    cout << 0 << nl;
    return;
}

a[0] = -2;
int ans = 0;
map<int,int> mp,np;
for(int i = 1;i <= 2 * n;i++){
    int k = a[i];
if(!mp[k]){
    if(!(a[i + 1] == k|| a[i - 1] == k)){
        mp[k] = a[i + 1];
        np[k] = a[i - 1];
    }

}
else{
    int x = a[i - 1],y = a[i + 1];
if(x == mp[k] && x != k){
    ans++;
}else
if(x == np[k] && x != k){
    ans++;
}

if(y == mp[k] && y != k){
    ans++;
}else 
if(y == np[k] && y != k){
    ans++;
}

}

}
cout << ans  << nl;
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
