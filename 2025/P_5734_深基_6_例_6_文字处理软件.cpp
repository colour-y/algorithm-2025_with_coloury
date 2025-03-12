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
    string s;
cin >> s;
string ans = s;
for(int i = 0;i < n;i++){
    int k;
    cin >> k;
    if(k == 1){
ans = ans + s;
cout << ans << nl;
    }else if(k == 2){
        int x,y;
        cin >> x >> y;
        ans = ans.substr(x,y);
        cout << ans << nl;
    }else if(k == 3){
        int x;
        string res;
        cin >> x >> res;
        ans = ans.substr(0,x - 1) + res + ans.substr(x,ans.back());
    }else{
        string res;
        cin >> res;
        int m = res.size();
        bool ok = 0;
        for(int j = 0;j < ans.size() - m;j++){
            if(ans.substr(j,m) == res){
                cout << j << nl;
                ok = 1;
                return;
            }
        }
        if(!ok){
            cout << - 1 << nl;
        }
    }
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

