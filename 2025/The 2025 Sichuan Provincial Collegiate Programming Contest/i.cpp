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
cin >> n;
set<string> st;
for(int i = 0 ;i < n;i++){
    string s;
    cin >> s;
    reverse(all(s));
    string q;
    for(auto c : s){
        q += c;
        st.insert(q);
    }
}
cout << st.size() << nl;
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

