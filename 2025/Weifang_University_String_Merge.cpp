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
string s;
cin >> s;
map<char,int> mp;
string a,b;
for(auto e : s){ 
    if(e == 'A' || e == 'E' || e == 'I' || e == 'O' || e == 'U'){
        a.push_back(e);
    }else{
        b.push_back(e);
    }
}
int n = a.size(),m = b.size();
if(n == 0 || m == 0){
    cout << s << nl;
    return;
}

int i = 0,j = 0;
while(i < n && j < m){
    if(a[i] < b[j]){
        cout << a[i];
        i++;
    }else{
        cout << b[j];
        j++;
    }
}

if(i == n){
    for(;j < m;j++){
        cout << b[j];
    }
}else{
    for(;i < n;i++){
        cout << a[i];
    }
}


}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}
