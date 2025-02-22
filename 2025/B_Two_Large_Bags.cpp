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
cin >> n;
vector<int> a(n);
map<int,int> mp;

for(auto &i : a){
    cin >> i;
mp[i]++;
}
for(auto &[x,y] : mp){
    if(y == 1){
        cout << "No" << nl;
        return;
    }
    if(y > 2){
        mp[x + 1] += y - 2; 
    }
}
cout << "Yes" << nl;
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
