#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  int query(int x){
    cout << "? " << x + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
  }

void solve(){
int n,k;
cin >> n >> k;

vector<int> a(k),b(k);
for(int i = 0;i < k;i++){
  a[i] = query(i);
}
for(int i = n - k;i < n;i++){
  b[i % k] = query(i);
}

vector<int> e;
int kt = 0;
for(int i = 0;i < k;i++){
  if(a[i] != b[i]){
    e.push_back(i);
    kt += (n - 2 * k ) / k;
    if(i < n % k) kt++;
  }
}

int lo = -1,hi = kt;
auto get = [&](int x) -> int{
if(x == -1){
  return k - 1;
}
if(x == kt){
  return n - k;

}
return x / e.size() * k + e[x % e.size() ] + k;
};

while(hi - lo > 1){
  int x = (lo + hi) / 2;
  int i = get(x);
  if(query(i) == a[i % k]){
    lo = x;
  }else{
    hi = x;
  }
}

lo = get(lo);
hi = get(hi);
if(hi - lo > 1){
  cout << "! " << -1 << endl; 
}else{
  cout << "! " << hi << " " << n - hi << endl;
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
