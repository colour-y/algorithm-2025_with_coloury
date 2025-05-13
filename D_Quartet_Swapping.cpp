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
vector a(2,vector<pair<int,int>>());
for(int i = 0,x;i < n;i++){
    cin >> x;
    a[i % 2 ].emplace_back(x,i + 1);

}

sort(all(a[0])),sort(all(a[1]));
vector<int> v(1),idx(1);
for(int i = 0;i < n;i++){
    v.push_back(a[i % 2][i / 2].first);
    idx.push_back(a[i % 2][i / 2].second);
}
vector<int> pos(n + 1);
for(int i = 1;i <= n;i++){
    pos[idx[i]] = i;
    }
    int cnt = 0;
    
    for(int i = 1;i <= n;i++){
        if(idx[i] != i){
            int  x = i,y = idx[i];
            swap(idx[i],idx[pos[i]]);
            swap(pos[x],pos[y]);
            cnt++;
        }
    }

    if(cnt % 2) swap(v[n - 2],v[n]);


for(int i = 1;i <= n;i++){
    cout << v[i] << " ";
}
cout << nl;
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
