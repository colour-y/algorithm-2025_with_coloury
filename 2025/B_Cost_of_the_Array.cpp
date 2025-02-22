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
int n,k;
cin >> n >> k;
vector<ll> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}

if(n == k){
    for(int i = 0;i < k / 2;i++){
        if(a[2 * i + 1] != i + 1){
            cout << i + 1 << nl;
            return;
        }
    }
    cout << k / 2 + 1 << nl;
    return;
}


for(int i = 1;i < n - k + 2;i++){
    if(a[i] != 1){
                cout << 1 << nl;
        return;
    }

}
cout << 2 << nl;
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
