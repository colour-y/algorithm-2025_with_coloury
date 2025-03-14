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
    std::cin >> n;
    
    std::vector<int> p(n);
    int r = n, x = 2 * std::sqrt(n);
    while (r > 0) {
        while (x * x > 2 * r - 2) {
            x--;
        }
        int v = x * x;
        for (int i = v - r + 1; i < r; i++) {
            p[i] = v - i;
          
        }
       
        r = v - r + 1;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " \n"[i == n - 1];
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
