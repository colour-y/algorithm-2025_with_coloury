#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve()
{
int n,k;
cin >> n >> k;
map<int,int> mp;
for(int i = 0;i < k;i++){
    int x,y;
    cin >> x >> y;
    mp[x]++;
    mp[y]++;
}

vector<int> e;
for(auto [x,y] : mp){
    if(y % 2 == 1){
        e.push_back(x);
    }
}
cout << e.size() / 2 << nl;
for(int i = 0;i < e.size();i += 2){
    cout << e[i] << " " << e[i + 1] << nl;
}

}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}

