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
ll kill,k,s;
cin >> n >> kill >> k >> s ;
vector<array<ll,3>> a(n);
for(int i = 0;i < n;i++){
    int hp,attack;
    cin >> attack >> hp;
    a[i] = {hp,attack,i};
}

sort(all(a));
vector<ll> mxb(n + 1),cnt(n,1);
for(int  i = n - 1; i>= 0;i--){
    mxb[i] = max(mxb[i + 1],a[i][1]);

}

ll mxs = 0,sum = 0;
int ans = 0;
for(int i  =0;i < n;i++){
    auto &[hp,attack,pos] = a[i];
    hp = max(0ll,hp - kill);
    ll c = (hp + kill / 2 - 1) / (kill / 2);
    if(c <= k - 1){
        sum += c * max(mxs,mxb[i]);
        if(sum < s){
            ans++;
        }
        sum += max(mxs,mxb[i + 1]);
    }else {
        sum += k * max(mxs,mxb[i]);
        mxs = max(mxs,attack);
    }
    if(sum >= s){
        break;
    }
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
