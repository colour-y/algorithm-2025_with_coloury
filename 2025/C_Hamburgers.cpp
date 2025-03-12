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
    string h;
    cin >> h;
    ll nb, ns, nc, pb, ps, pc, moedas, b = 0, s = 0, c = 0;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> moedas;

    for(auto i: h) if(i == 'B') b++;
    else if(i == 'S') s++;
    else c++;

    ll l = 0, r = 1e14, resp = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        ll qtb = (max(0LL, b*mid - nb)*pb), qts = (max(0LL, s*mid - ns)*ps), qtc = (max(0LL, c*mid - nc)*pc);
        if(qtb + qts + qtc <= moedas){
            resp = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << resp << "\n";
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
