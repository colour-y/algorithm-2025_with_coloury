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
ll n,x,y;
cin >> n >> x >> y;
string a,b,c;
cin >> a >> b >> c;

if(x * 2 <= y){
    ll res = 0;
    for(int i = 0;i < n;i++){
        int j = a[i] - '0';
        int k = b[i] - '0';
        int l = c[i] - '0';
        if(k ^ j != l) {
res++;
        }

    }
    cout << res * x << nl;
   
}else{
    ll c0 = 0,c1 = 0,c2 = 0,c3 = 0,c4 = 0;
for(int i = 0;i < n;i++){
        int j = a[i] - '0';
        int k = b[i] - '0';
        int l = c[i] - '0';
        if(j == 0 && k == 0 && l == 1){
            c1++;
        }else if(j == 1 && k == 1 && l == 1){
            c2++;
        }else if(j == 1 && k == 0 && l == 0){
            c3++;
        }else if(j == 0 && k == 1 && l ==  0){
            c4++;
        }
if(j ^ k != l) c0++;
}

        int tot = min(c0 / 2, c0 - max({c1, c2, c3, c4}));
        cout << tot * y + x * (c0 - tot * 2) << nl;

}


}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
