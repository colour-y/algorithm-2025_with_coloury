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
int n,k;
cin >> n >> k;
string s;
cin >> s;
s = 'R' + s + 'R';
vector<int> a(n + 1);
for(int i = 1; i <= n ;i++){
    cin >> a[i];
}
int ans = 0;
vector<int> l(n + 2),r(n + 2);
for(int i = 1;i <= n + 1;i++){
    l[i] = i - 1;
    r[i - 1]  = i;
}


vector<int> p(n);
iota(all(p),1);
sort(all(p),[&](int i,int j){
    return a[i] < a[j];
});

int cost = 0;
for(int i = 1;i <= n + 1;i++){
    cost += (s[i] != s[i - 1]);
}
for(auto i : p){
    if(cost <= 2 * k){
        break;
    }
    cost -= (s[i] != s[l[i]]);
    cost -= (s[i] != s[r[i]]);
    cost += (s[l[i]] != s[r[i]]);
    r[l[i]] = r[i];
    l[r[i]] = l[i];
    ans = a[i];
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
