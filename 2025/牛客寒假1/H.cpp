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
int n;
cin >> n ;
vector<int> l(n),r(n);
vector<int> p(n);
vector<vector<int>> vec(n);
for(int i = 0;i < n ;i++){
  cin >> l[i] >> r[i];
  l[i]--;
  vec[l[i]].push_back(i);
}

priority_queue<array<int,2>,vector<array<int,2>>,greater<>> pq;
for(int x = 0 ;x < n;x++){
  for(auto i : vec[x]){
    pq.push({r[i],i});
  }
  if(pq.empty()){
    cout << -1 << nl;
    return;
  }
  auto [r,i] = pq.top();
  pq.pop();
  if(x >= r){
    cout << -1 << nl;
    return;
  }
  p[i] = x;
}
for(int i = 0;i < n;i++){
  cout << p[i] + 1 << nl;
}
cout << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
