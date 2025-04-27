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
vector<vector<int>> a(n);
for(int i = 0;i < n - 1;i++){
    int x,y;
    cin >> x >> y;
    x--,y--;
    a[x].push_back(y);
}

vector<int> b;
for(int i = 0;i < n;i++){
    if(a[i].size() == 1){
        b.push_back(i);
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
