#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  const int N = 1e6 + 5;
void solve(){
int n;
cin >> n;
vector<int> a(n);
for(auto &e : a){
  cin >> e;
}

vector<bool> ok(N);
vector<bool> ex(N);

set<int> st;

int l = 0;

vector<int> pre(n);
for(int i = 0;i < n;i++){
  if(a[i] == 0){
    while(l < i){
      ok[a[l++]] = 1;
      
    }
    
  }else {
    if(ok[a[i]]){
      st.insert(a[i]);
    }
  }
  pre[i] = st.size();
}

ll ans = 0;
for(int i = n - 1;i >= 3;i--){
  if(ex[a[i]] || a[i] == 0) continue;
  ans += pre[i - 1];
  ex[a[i]] = 1;
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
