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
vector<int> a(2 * n);
for(auto &e : a){
    cin >> e;
    e--;
}

map<pair<int,int>,vector<int>> f;
for(int i = 1;i < 2 * n;i++){

    f[minmax(a[i - 1],a[i])].push_back(i);

}

int ans = 0;
for(auto [_,p] : f){
    if(p.size() == 2){
        if(p[1] - p[0] > 2){
            ans++;
        }
        
    }
    else if(p.size() == 3){
        ans++;
    }
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
