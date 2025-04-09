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
int q;
cin >> q;
while(q--){
    string s;
    cin >> s;
    if(s == "->"){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        ll d = 0;
        for(int i = 0 ;i < n ;i++){
            int xi = x >> i & 1;
            int yi = y >> i & 1;
            ll di = (xi * 2) ^ (yi * 3);
d |= di << (2 * i);
        }
cout << d + 1 << nl;
    }else{
        ll d;
        cin >> d;
        d--;
        int x = 0,y = 0;
        for(int i  =0 ;i < n;i++){
            int di = d >> (2 * i ) & 3;
            int xi = (di & 1) ^ (di >> 1);
            int yi = di & 1;
            x |= xi << i ;
            y |= yi << i;
        }
        cout << x + 1 << " " << y + 1 << nl;
 
    }
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
