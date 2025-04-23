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
vector<int> a(n );
for(int i = 0;i < n;i++){
int x;
cin >> x;
if(x <= k) a[i] = 1;
else a[i] = -1;
}
vector<int> c(n);
c[0] = a[0];
int e = 0;
for(int i = 1 ;i < n;i++){
c[i] = c[ i - 1];
c[i] += a[i];
if(c[i] >= 0) e++;
if(e >= 2 && i != n - 1){
    cout << "YES" << nl;
    return;
}
}
e = 0;
vector<int> d(n);
d[n - 1] = a[n - 1];
for(int i = n - 2;i >= 0;i--){
d[i] = d[i + 1];
d[i] += a[i]; 
if(d[i] >= 0) e++;
if(i != 0 && e >= 2){
    cout << "YES" << nl;
    return ;
}
}


int i = 0,j = n - 1;
while(i < n - 1){
    if(c[i] >= 0) break;
i++;
}
while(j > 0){
    if(d[j] >= 0) break;
    j--;
}

if(i < j){
    cout << "YES" << nl;
    return;
}




cout << "NO" << nl;
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
