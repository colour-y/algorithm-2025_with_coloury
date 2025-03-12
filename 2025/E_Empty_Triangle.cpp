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
if(n == 3){
    cout << "! 1 2 3" <<endl;
    return; 
}
vector<int> a(3);
a[0] = n;
a[1] = 1;
a[2] = (n + 1) / 2;
int k;
while(cin >> k && k != 0 && k != -1){
    int x = rand() % 3;
    a[x] = k;

cout<< "? " << a[0] << ' ' << a[1] << ' '<< a[2] << endl;
}
cout<< "! " << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
}


int main(){

int t = 1;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
