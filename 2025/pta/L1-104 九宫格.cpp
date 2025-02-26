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
vector<vector<int>> a(9,vector<int>(9));
for(int i = 0;i < 9;i++){
    for(int j = 0;j < 9;j++){
        cin >> a[i][j];
    }
}




for(int i =0 ;i < 9;i++){
    vector<int> b(10),c(10);
    for(int j = 0;j < 9;j++){
        int x = a[i][j];
        if(x >= 10 || x <= 0){
            cout << 0 << nl;
            return;
        }
        if(b[x]){
            cout << 0 << nl;
            return;
        }
        else b[x]++;


        int y = a[j][i];
        if(y >= 10 || y <= 0){
            cout << 0 << nl;
            return;
        }
        if(c[y]){
            cout << 0 << nl;
            return;
        }else{
            c[y]++;
        }
    }
   
}

//这里的写得复制了一点实际上是能简便点的，但是由于错了几次，我觉得对于pta这种狗屎题来说还是写得小心一点比较好，别在这种煞笔题上费太多时间。


for(int i = 0;i < 9;i++){
int jj = i / 3;
int kk = i % 3;
vector<int> d(10);
    for(int j = 0;j < 3;j++){
        for(int k = 0;k < 3;k++){
int x = j + jj * 3,y = k + kk * 3;
if(a[x][y] >= 10 || a[x][y] <= 0 || d[a[x][y]]){
  cout << 0 <<nl;
    return;
}else{
    d[a[x][y]]++;
}
        }
    }
    for(int i = 1;i <= 9;i++){
        if(!d[i]){
            cout << 0 << nl;
            return;
        }
    }
}

cout << 1 << nl;
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
