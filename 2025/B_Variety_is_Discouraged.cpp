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
map<int,int> mp;

vector<int> a(n + 1);
for(int i = 0;i < n;i++){
    cin >> a[i];
    mp[a[i]]++;
}
if(n == 1){
    cout << 1 << " " << 1 << nl;
    return;
}
if(mp[a[0]] == n){
    cout << 0 << nl;
    return;
}
int ans = 0;
int res = 0;
int l = 0,r = -1;
for(int i = 0;i < n;i++){
    if(mp[a[i]] == 1){
        res++;
    }
    else if(mp[a[i]] > 1 ){
       if(res > ans){
        ans = res;
        r = i - 1;
        l = i - ans;
       }
       res = 0;
    }

}
if(res > ans){
    ans = res;
    res = 0;
    r = n - 1;
    l = n - ans;
}
if( r == -1){
cout << 0 << nl;
return;
}
cout << l + 1<< " "<< r + 1<<  nl;
//我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛为什么过不了我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛我草尼玛我曹尼玛曹尼玛
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