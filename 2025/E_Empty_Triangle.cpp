#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void solve(){
int n;
cin >> n;
int i[3]{1,2,3};

while(1)
{
  cout << "? " << i[0] << " " << i[1] << " " << i[2] << endl;
  int k;
  cin >> k ;
  if(k == 0){
    break;
  }
  int x = rng() % 3;
  i[x] = k;
}
cout << "! " << i[0] << " " << i[1] << " " << i[2] << endl;



}




int main(){

int t = 1;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
