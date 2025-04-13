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
ll a,b;
cin >> n >> a >> b;
vector<ll> p,q;
for(int i = 0;i < n;i++){
    ll x;
    cin >> x;
    if(x != -1){
        p.push_back(x);
    }
}

for(int i = 0;i < n;i++){
    ll x;
    cin >> x;
    if(x != -1){
        q.push_back(x);
    }
}

sort(all(p),greater());
sort(all(q));

for(int i = 0;i < p.size() && i < q.size() ;i++){
    b -= p[i];
    a -= q[i];
    if(a <= 0){
        cout << "no" << nl;
        return;
    }

    if(b <= 0){
       
        cout << "yes" << nl;
        return;
    }
}
cout << "no" << nl;
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
