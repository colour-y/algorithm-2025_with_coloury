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
string a;
cin >> a;
vector<int> pre(n + 1);
for(int i = 0;i < n;i++){
    pre[i + 1] = pre[i] + a[i] - '0';
}
int i = -1;
for(int j = 0;j <= n;j++){
int left = j - pre[j];
int right = pre[n] - pre[j];
if(left * 2 >= j && right * 2 >= n - j){
    if(i == -1  || abs(n - 2 * j) < abs(n - 2 * i)){
        i = j;
    }
}

}
cout << i << nl;
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
