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
    int n, k;
    std::cin >> n >> k;
    
    std::string A;
    std::cin >> A;
    
    int a = std::count(A.begin(), A.end(), '1');
    
    for (int b = 0; b <= n + k && b < (1 << k); b++) {
        if (a + __builtin_popcount(b) == b) {
            for (int i = k - 1; i >= 0; i--) {
                std::cout << (b >> i & 1);
            }
            std::cout << "\n";
            return;
        }
    }
    std::cout << "None\n";
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
