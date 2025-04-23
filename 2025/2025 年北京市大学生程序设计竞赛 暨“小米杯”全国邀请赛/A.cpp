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
string s;
cin >> n >> s;
if(s[0] != s[n - 1]){
    cout << "empty" << nl;
    return;
}
int m = count(all(s),s[0]);
if(n == m){
    cout << s << nl;
    return;
}
char c = s[0];
int k = (c - '0') ^ 1;
c = k + '0';
vector<int> a;
int e = 0;
for(int i = 0;i < n;i++){
if(s[i] == c) {
    e++;
a.push_back(i + 1);
}
else e = 0;
if(e == 2){
    cout << "empty" << nl;
    return;
}
}

if(a.size() == 1){
    cout << string(min(a[0] - 1,n - a[0]),s[0]) << nl;
    return;
}

vector<int> b;
b.push_back(a[0] - 1);
b.push_back(n - a[a.size() - 1]);
for(int i = 1;i < a.size();i++){
    b.push_back(a[i] - a[i - 1] - 1);

}
ranges::sort(b);
cout << string(b[0],s[0]) << nl;
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
