#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(int n){

vector<int> a(n);
map<int,int> mp;
for(auto &k : a)
{
    cin >> k;
    mp[k]++;
    if(mp[k] == 1){
      cout << k << " ";
    }
}


}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n;
while(cin >> n)
    solve(n);

    return 0;
}
