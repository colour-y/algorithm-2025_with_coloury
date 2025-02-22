#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

int LCP(const string &a, const string &b) {
    int len = 0;
    while (len < a.size() && len < b.size() && a[len] == b[len]) {
        len++;
    }
    return len;
}



void solve(){
    int n,k;
    cin >> n >> k;
vector<string> s(n);
int mx = 0;
for(int i = 0;i < n;i++){
    cin >> s[i];
    int k = s[i].size();
    mx = max(k,mx);
}
int l,r;
cin >> l >> r;
    // 对字符串进行排序
    sort(s.begin(), s.end());
    int ans = 0;
for(int i = 0;i < n ;i++){
ans += (int)s[i].size() * 2;
if(i) ans -= LCP(s[i],s[i - 1]) * 2;
 
} 
 
cout << ans - mx<< nl;

}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}