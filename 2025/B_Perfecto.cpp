#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

bool isSquare(ll n){
    int x = sqrt(n);
    return 1LL * x * x == n;
}

void solve() {
int n;
cin >> n ;
ll sum = 1LL * n * (n + 1) / 2;
if(isSquare(sum)){
    cout << - 1 << nl;
    return;
}

vector<int> ans(n);
iota(all(ans),1);
for(int i = 1;i < n;i++){
    if(isSquare(1ll * i * (i + 1) / 2)){
        swap(ans[i],ans[i - 1]);
    }
}
for(auto x : ans){
    cout << x << " ";
}
cout << nl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}