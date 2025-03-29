#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  vector<std::string> thirteen {"1m", "1p", "1s", "1z", "2z", "3z", "4z", "5z", "6z", "7z", "9m", "9p", "9s"};
void solve(){
string s;
cin >> s;

vector<string> a;
for(int i =0 ;i < 14;i++){
    a.push_back(s.substr(2 * i,2));
}
ranges::sort(a);

auto b = a;
b.erase(unique(all(b)),b.end());
if(b == thirteen){
    std::cout << "Thirteen Orphans\n";
        return;
}
for(int i = 0;i < 13;i++){
    if((a[i] == a[i + 1]) != (i % 2 == 0)){
     std::cout << "Otherwise\n";
        return;
    }
}
std::cout << "7 Pairs\n";
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
