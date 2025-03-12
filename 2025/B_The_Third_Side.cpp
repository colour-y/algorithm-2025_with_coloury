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
vector<int> a(n);
priority_queue< int, vector< int>> pq;
for(auto &e : a){
    cin >> e;
    pq.push(e);
}
if(n == 1){
    cout << a[0] << nl;
    return;
}

while(pq.size() >= 2){
int x = pq.top();
pq.pop();
int y = pq.top();
pq.pop();
pq.push(x + y - 1);
}
cout << pq.top() << nl;

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
