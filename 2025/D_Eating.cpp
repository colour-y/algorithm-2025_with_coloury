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
int n,q;
cin >> n >> q;
vector<int> w(n);
for(int i = 0;i < n;i++){
    cin >> w[i];
}

vector<array<int,30>> left(n);
vector<array<int,30>> pre(n);
for(int i = 0;i < n;i++){
    if(i){
        left[i] = left[i - 1];
    pre[i] = pre[i - 1];
    }else{
        left[i].fill(-1);
    }
    int d = __lg(w[i]);
    for(int j = 0;j <= d;j++){
        left[i][j] = i;
        pre[i][j] = 0;
    }
    for(int j = d + 1;j < 30;j++){
        pre[i][j] ^= w[i];
    }
}

for(int i = 0;i < q;i++){
    int x;
    cin >> x;
    int j = n - 1;
    while(x > 0 && j >= 0){
        int d = __lg(x);
        int k = left[j][d];
        x ^= pre[j][d];
        j = k;
        if(j == -1){
            break;
        }
        if(x < w[j]){
            break;
        }
        x ^= w[j];
        j--;
    }
    cout << n - 1 - j << " ";
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
