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
ll n,x;
cin >> n >> x;


if(x == 0){
    if(n == 1){
        cout << -1 << nl;

    }
else if(n % 2 == 0){
    cout << n << nl;
}else{
cout << n + 3 << nl;
}
    return;
}

if(x == 1){
    if(n % 2 == 1){
        cout << n << nl;
    }else{
        cout << n + 3 << nl; 
    }
    return;
}

int k = 0;
ll e = x;
while(e){
    if(e & 1) k++;
    e >>= 1;
}

n -= k;

if(n < 0){
cout << x << nl;
return;
}

if(n % 2 == 0){
    cout << n + x << nl;
    return;
}else{
   
     cout << n + x + 1 << nl;
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
