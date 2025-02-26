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

vector<string> s = {
    "ling",
    "yi",
    "er",
   "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu",
};

string k;
cin >> k;
int n = k.size();
int i = 0;
if(k[0] == '-'){
    cout << "fu ";
    i++;
}
for(;i < n;i++){
cout << s[k[i] - '0'];
if(i != n - 1) cout << " ";//煞笔pta判题特色段错误和格式错误指最后输出空格也算
}
cout << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
