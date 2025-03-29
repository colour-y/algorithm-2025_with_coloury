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
cin >> n;

string s;
cin >> s;

if(count(all(s),s[0]) == n){
    cout << -1 << nl;
    return;
}

vector<int> a(n);
int cnt[3]{};
for(int i  = 0;i < n;i++){
    a[i] = s[i] == 'L' ? 0 : s[i] == 'I' ? 1 : 2;
cnt[a[i]]++;
}


vector<int> ans;
int mi = *min_element(cnt,cnt + 3);
for(int x = 0;x < 3;x++){
    if(cnt[x] == mi){
        continue;
    }
    int p = 1;
    while((a[p] == x ) == (a[p - 1] == x)){
        p++;
    }
    while(cnt[x] > mi){
        if (a[p] == x) {
            int y = a[p - 1];
            a.insert(a.begin() + p, 3 - x - y);
            ans.push_back(p);
            a.insert(a.begin() + p + 1, y);
            ans.push_back(p + 1);
            p += 2;
        } else {
            int y = a[p];
            a.insert(a.begin() + p, 3 - x - y);
            ans.push_back(p);
            a.insert(a.begin() + p, y);
            ans.push_back(p);
        }
        cnt[x]--;
    }
}
cout << ans.size() << nl;
for(auto x : ans){
    cout << x << nl;
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
