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
    vector a(3,vector<char>(3));
    int res = 0 ;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            char c;
            cin >> c;
            if(c == 'X') a[i][j] = 2;
            else if(c == 'O'){
                a[i][j] = -10;
                res++;
            }
            else a[i][j] = 1;
        }
    }
    if(res <= 2){
        cout << "Yes" << nl;
        return;
    }else{
        for(int i = 0;i < 3;i++){
            if(a[i][0] + a[i][1] + a[i][2] > 3){
                cout << "Yes" << nl;
                return;
            }
            if(a[0][i] + a[1][i] + a[2][i] > 3){
                cout << "Yes" << nl;
                return;
            }
        }

        if(a[2][0] + a[1][1] + a[0][2] > 3 || a[0][0] + a[1][1] + a[2][2] > 3){
            cout << "Yes" << nl;
            return;
        }
    }
    cout << "No" << nl;
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
