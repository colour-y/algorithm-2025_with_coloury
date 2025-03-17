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
string s;
cin >> s;
vector<string> a = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
vector<string> b = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

for(int i = 0;;i++){
    string ans;
    ans = a[i % 10 ] + b[i % 12];
    if(ans == s){
        cout << 1984 + i << nl;
        break;
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
