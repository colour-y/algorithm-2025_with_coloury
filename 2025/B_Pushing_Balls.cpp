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
int n,m;
cin >> n >> m;
vector<string> s(n);
for(auto &e : s){
    cin >> e;
}
for(int i = 1;i < n;i++){
    for(int j = 1;j < m;j++){
if(s[i][j] == '1' && (s[i - 1][j] == '0' && s[i][j - 1] == '0')){
    cout << "NO" << nl;
    return;
}
    }
}

vector<vector<int>> a(n + 1,vector<int>(m + 1)),b(n + 1,vector<int>(m + 1));
for(int i = 1;i <= n;i++){
for(int j = 1;j <= m;j++){
a[i][j] = a[i][j - 1];
a[i][j] += s[i - 1][j - 1] ==  '0';
}
}

for(int j = 1;j <= m;j++){
    for(int i = 1;i <= n;i++){
    b[i][j] = b[i - 1][j];
    b[i][j] += s[i - 1][j - 1] ==  '0';
    }
    }

for(int i = 1;i < n;i++)
{
    for(int j =  1;j < m;j++){
if(s[i][j] == '1' && a[i + 1][j + 1] && b[i + 1][j + 1]){
    cout << "NO" << nl;
    return;
}
    }
}

cout << "YES" << nl;
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
