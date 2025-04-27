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
string s;
cin >> s;
map<int,int> mp;
for(auto c : s){
int x = c - '0';
mp[x]++;

}
for(int i = 9;i >= 0;i--){
    if(mp[i]){
        cout << i;
        mp[i]--;
    }else{
        for(int j = i;j <= 9;j++){
            if(mp[j]){
                cout << j;
                mp[j]--;
                break;
            }
        }
    }
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
