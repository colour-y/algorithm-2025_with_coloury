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
vector<ll> a(n);
for(auto &e : a){
    cin >> e;
}

if(n == 2){
    if(a[0] == a[1]){
        cout << "Yes" << nl;
        return;
    }else{
        cout << "No" << nl;
        return;
    }
}
ranges::sort(a);
ll k = a[0];

if(n == 3){
    if(min(a[1],a[2]) == a[0]){
        cout << "Yes" << nl;
        return ;
    }
}
ll d;
ll c = 1;
for(int i = 1;i < n ;i++){
if(a[i ] % k == 0){
   if(c == 1){
    d = a[i] / k;
    c--;
   }else{
    d = gcd(a[i] / k,d);
   }
}

if(d == 1){
    cout << "Yes" << nl;
    return;
}


}



cout << "No" << nl;
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
