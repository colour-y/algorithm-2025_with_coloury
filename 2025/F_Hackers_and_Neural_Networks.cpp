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
vector<string > a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}

vector b(m,vector<string>(n));
for(int i = 0;i < m;i++){
    for(int j = 0;j < n;j++){
        cin >> b[i][j];
    }
}


for(int j = 0;j < n;j++){
    auto ok = 0;
    for(int i = 0;i < m;i++){
        if(b[i][j] == a[j]){
            ok = 1;
        }
    }
    if(!ok){
        cout << -1 << nl;
        return;
    }
}

int ans = 0;
for(int i = 0;i < m;i++){
    int cnt = 0;
    for(int j = 0;j < n;j++){
        cnt += (b[i][j] == a[j]);
    }
    ans = max(ans,cnt);
}
ans = 3 * n - 2 * ans;
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
