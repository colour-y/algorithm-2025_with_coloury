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
int n;
cin >> n;
vector<string> s(n);
for(int i = 0 ;i < n;i++){
    cin >> s[i];
}
vector<int> ans(n,-1);
  for (int i = n - 1; i >= 0; i--) {
        int k = 0;
        for (int j = 0; j < i; j++) {
            k += (s[j][i] == '1');
        }
        for (int j = 0; j < n; j++) {
            if (ans[j] == -1) {
                if (k == 0) {
                    ans[j] = i;
                
                    break;
                }
                k--;
            }
        }
    }
for(int i = 0;i < n;i++){
cout << ans[i] + 1 << " ";
}
cout<< nl;
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
