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
int n,m;
cin >> n >> m;
string s;
cin >> s;
vector<bool> vis(n + m - 2);
vector<vector<ll>> a(n,vector<ll>(m));
for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
        cin >> a[i][j];
    }
}
vector<ll> nk(n),mk(m);
for(int i = 0;i < n;i++){
    nk[i] = accumulate(a[i].begin(),a[i].end(),0LL);
}

for(int i = 0 ;i < m;i++){
    for(int j = 0 ;j < n;j++){
        mk[i] += a[j][i];
    }
}
int l = 0,r = 0;
int k = 0;

ll ki = lcm(n,m);
while(1){
ll li = -1e15 / ki,ri = 1e15 /ki;
ll mid = (li + ri) / 2;
ll x = mid * ki;
while(k < n + m - 2){
    if(s[k] == 'D'){
a[l][r] = x - nk[l];
mk[r] += a[l][r];
l++;
k++; 
    }
    else{
        a[l][r] = x - mk[r];
        nk[l] += a[l][r];
        r++;
        k++;

    }
}
if(nk[n - 1] == mk[m - 1]){
a[n - 1][m - 1] = x - nk[n - 1];
    break;
}
else if

}

for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
        cout << a[i][j] << " ";
    }
    cout << nl;
}


}



int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
