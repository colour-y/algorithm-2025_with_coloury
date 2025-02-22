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
vector<ll> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}

if(accumulate(a.begin(),a.end(),0LL) !=1LL *  n * (n + 1) / 2 ){
    cout << -1 << nl;
    return;
}

ranges::sort(a);
ll k = 0;
for(int i = 0;i < n;i++){
    if(a[i] < i + 1){
        k += i + 1 - a[i];
    }else{
        k += a[i] - i - 1;
    }
}
cout << k / 2 << nl;

}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
