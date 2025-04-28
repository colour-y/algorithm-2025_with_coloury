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
    int n = s.size();


    for(int m = n/2; m >= 1; --m){
        int cnt = 0;
    
        for(int i = 0; i + m < n; ++i){
            char a = s[i], b = s[i + m];
            if(a == b || a == '?' || b == '?'){

                ++cnt;
                if(cnt >= m){

                    cout << 2*m << nl;
                    return;
                }
            } else {

                cnt = 0;
            }
        }
    }


    cout << 0 << nl;
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