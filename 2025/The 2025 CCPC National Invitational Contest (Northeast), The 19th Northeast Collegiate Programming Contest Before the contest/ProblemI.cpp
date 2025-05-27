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
int n,s,t;
cin >> n >> s >> t;

map<int,int> mp;
for(int i = 1;i <= n;i++){
    int x;
    cin >> x;
    mp[x] = i;
    mp[i] = x;
}


if(s == t){
    cout << "Yes" << nl;
    return;
}

if(mp[s] == t || mp[t] == s){
    cout << "No" << nl;
    return;
}

if(n == 1){
    cout << "No" << nl;
    return;
}

if(n >= 3){
    cout << "Yes" << nl;
    return;
}

if((s <= n && t <= n) || (s > n && t > n)){
    cout << "No" << nl;
    return;
}

cout << "Yes" << nl;


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

