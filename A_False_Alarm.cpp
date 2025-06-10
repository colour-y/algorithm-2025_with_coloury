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
int n,x;
cin >> n >> x;
vector<int> a(n);
for(auto &e : a){
    cin >> e;
}
int i = 0;
for( i = 0;i < n;i++)
{
if(a[i] == 1) break;
}

int j = n - 1;
for(;j >= 0;j--){

    if(a[j] == 1) break;
    
}


int ans = j - i  + 1;
if(ans <= x) cout << "Yes" << nl;
else cout << "No" << nl;

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

