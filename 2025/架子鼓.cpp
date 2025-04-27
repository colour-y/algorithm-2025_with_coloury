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
int n,m;
cin >> n >> m;
set<int> st,s1,s2;
int k = 0;
for(int i = 0;i < n;i++){
    int x,y;
    cin >> x >> y;
    if(i == n - 1) continue;
 k += 48 / y * x;
 s1.insert(k);
    st.insert(k);

}
k = 0;
for(int i = 0;i < m;i++){
    int  x,y;
    cin >> x >> y;
    if(i == m - 1) continue;
    k += 48 / y * x;
    st.insert(k);
    s2.insert(k);

}
// cout << s1.size() << ' ' << s2.size() << " " << st.size() << nl;
cout << s1.size() + s2.size() - st.size() + 1 << nl;
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
