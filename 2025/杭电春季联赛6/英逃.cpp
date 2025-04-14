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
ll x;
cin >> n >> x;
vector<ll> a(n);
for(auto &e : a){
    cin >> e;
}

vector<ll> sum(n + 1);
for(int i = 1;i <= n;i++){
    sum[i] += sum[i - 1] + (i != n ? abs(a[i] - a[i - 1]) : 0);

}

if(sum[n] <= x){
    cout << 0 << nl;
    return;
}

auto check = [&](int len) -> auto{
    deque<int> que;
    for(int i = 0;i < len;i++){
        
    }
}

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
