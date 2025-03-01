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
string s,t;
cin >> s >> t;
int ans = t.size();
for(int i = 0;i < t.size();i++){
    int k = i;
    for(int j = 0;j < s.size();j++){
        if(k < t.size() && s[j] == t[k]){
            k++;
        }
    }
    ans = min(ans,i + int(t.size()) - k);

    
}
cout << ans + s.size() << nl;
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
