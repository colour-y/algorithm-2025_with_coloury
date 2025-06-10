#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()


int get(int a,int b)
{
    int la = a & -a;
    int lb = b & -b;
    if(a / la != b / lb || a < b){
        return la;
    }
    return la - 2 * lb + 1;
}

void solve()
{
int n,k;
cin >> n >> k;
vector<int> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}

vector<ll> pre(n),suf(n);
for(int i = 1;i < n;i++){
    pre[i] = pre[i - 1] + get(a[i - 1],a[i]);
}

for(int i = n - 2;i >= 0;i--)
{
    suf[i] = suf[i + 1] + get(a[i + 1],a[i]);
}
for(int i = 0;i < n;i++){
    if(pre[i] + (a[i] & -a[i]) + suf[i] >= k)
    {
        cout << "YES" << nl;
        return;
    }
}
cout << "NO" << nl;
// cout << l << " " << r << nl;
// cout << cph(96) << nl;
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

