#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve()
{
int n;
cin >> n ;
vector<ll> a(n),left(n),right(n);
for(auto &e : a){
    cin >> e;
}

for(int i = 0;i < n;i++)
{
    int c = 1;
    for(int j = i - 1;j >= 0;j--){
        if(a[j] == a[i]){
            c = left[j] + (i - j );
            break;
        }
        if(a[j] > a[i] && a[j] % a[i] == 0){
            c++;
        }else{
            break;
        }
    }
    left[i] = c;
}

for(int i = n - 1;i >= 0;i--){
    int c =  1;
    for(int j = i + 1;j < n;j++){
        if(a[j] == a[i]){
            c = right[i] + j - i;
            break;
        }
        if(a[j] > a[i] && a[j] % a[i] == 0){
            c++;
        } else{
            break;
        }
    }
    right[i] = c;
}
ll ans = 0;
for(int i = 0;i < n;i++){
    ans += ll(left[i] * right[i]);
}
cout << ans << nl;
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

