#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  vector<int> cur(400,0);
void solve(){
int n;
cin >> n;

vector<int> ncur(400,0);
bool ok = 0;
for(int i = 0;i < 400;i++){
    if(n >= cur[i]){
        n -= cur[i];
        ncur[i] = cur[i];
    }
    else{
        ok = 1;
        for(int j = i - 1;j >= 0;j--){
            if(n && ncur[j] != 9){
                ncur[j]++;
                n--;
                break;
            }
            else{
                n += ncur[j];
                ncur[j] = 0;
            }
        }
        break;
    }
}

if(!ok){
    if(n){
        ncur.back()++;
        n--;
    }
    else{
        for(int j = 399;j >= 0;j--){
            if(n && ncur[j] != 9){
                ncur[j]++;
                n--;
                break;
            }
            else{
                n += ncur[j];
                ncur[j] = 0;
            }
        }
    }
}

for(int j = 399;j >= 0;j--){
    int v = min(n,9 - ncur[j]);
    ncur[j] += v;
    n -= v;
}
ok = 0;
cur.swap(ncur);

for(int j = 0;j < 400;j++){
    if(cur[j]) ok = 1;
    if(ok) cout << cur[j];
    
}
cout << nl;
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
