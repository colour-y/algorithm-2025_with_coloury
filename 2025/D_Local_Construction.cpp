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

vector<int> a(n);
for(int i = 0;i < n;i++){
    cin >> a[i];
}

vector<int> p(n);
int l = 1,r = n;

vector<int> b(n);
iota(all(b),0);

for(int t = 1;b.size() > 1;t++){
    int x = 0;
    while(a[b[x]] == t){
        x++;
    }

    for(int i = 0;i < x;i++){
        if(a[b[i]] == t){
            p[b[i]] = t % 2 == 1 ? r-- : l++;
        }
    }

    for(int i = b.size() - 1;i > x;i--){
        if(a[b[i]] == t){
            p[b[i]] = t % 2 == 1 ? r-- : l++;
        }
    }

    vector<int> np;
    for(auto i : b){
        if(a[i] != t){
            np.push_back(i);
        }
    }
b = move(np);
}
p[b[0]] = l;
for(int i = 0;i < n;i++){
    cout << p[i] << " \n"[i == n - 1];
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
