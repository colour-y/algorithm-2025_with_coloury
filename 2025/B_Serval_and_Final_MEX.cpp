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
vector<int> a(n);
map<int,int> mp; 
for(auto &e : a){
    cin >> e;
    mp[e]++;
}

if(!mp[0]){
    cout << 1 << nl;
    cout << 1 << " " << n << nl;
    return;
}

if(mp[0] == n){
    cout << 3 << nl;
cout << 3 << " " << n << nl;
cout << 1 << " " << 2 << nl;
cout << 1 << " " << 2 << nl;
return;
}

if(a[0] != 0 ){
    cout << 2 << nl;
    cout << 2 << " " << n << nl;
    cout << 1 << " " << 2 << nl;
    return;
}else if(a[n - 1] != 0){
    cout << 2 << nl;
    cout << 1 << " " << n - 1 << nl;
cout << 1 << " " << 2 << nl;
return;
}

int k = 0;
for(int i = 0;i < n;i++){
if(a[i] != 0){
    k = i + 1;
    break;
}
}


if(k == 2){
    cout << 3 << nl;
    cout << 3 << " " << n <<  nl;
    cout << 1 << " " << 2 << nl;
    cout << 1 << " " << 2 << nl;
    return;
}else {
    cout << 3 << nl;
    cout << 1 << " " << n - 2 << nl;
    cout << 2 << " " << 3 << nl;
    cout << 1 << " " << 2 << nl;
    return;
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
