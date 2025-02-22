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
vector<ll> a(n);
map<ll,ll> mp;
for(int  i = 0;i < n ;i++){
    cin >> a[i];
    mp[a[i]]++;
}
if(n % 2 == 1){
    cout << "No" << nl;
    return;
}
ranges::sort(a);
if(a[0] == a[n - 1]){
        cout << "No" << nl;
    return;
}
if(mp[a[0]] + mp[a[n - 1]] != n || mp[a[0]] != mp[a[n - 1]]){
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
