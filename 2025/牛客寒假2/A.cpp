#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
bool ok = 1;
for(int i  =0 ;i < 7;i++)
{
    int x;
    cin >> x;
    if(x != 1 && x != 2 && x != 3 && x != 5 && x != 6){
        ok = 0;
    }
}
if(!ok){
    cout << "NO";
}else{
    cout << "YES";
}
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
