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
vector<int> a(n);
int l = 0,r = 0;
int ans = 0;
for(int i = 0;i < n;i++){
    cin >> a[i];
    if(a[i] % 2 == 0){
        l++;
    }else r++;
}
if(l !=0 ) 
{ans++;
ans += r;}
else{
    r--;
    ans += r;
}
cout << ans << nl;
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
