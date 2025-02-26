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
map<int,pair<string,int>> mp;
int n;
cin >> n;
for(int i = 0 ;i < n;i++){
    int x,y;
    string s;
    cin >> s >> x >> y;
    mp[x].first = s;
    mp[x].second = y;
}
int m;
cin >> m;
for(int i = 0 ;i < m;i++){
    int x;
    cin >> x;
    cout << mp[x].first << " "<< mp[x].second << nl;
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
