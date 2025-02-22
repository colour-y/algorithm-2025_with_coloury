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
int n,m;
cin >> n >> m;
string a,b;
cin >> a >> b;
map<char,int> mp1,mp2;
if(n > m){
    swap(a,b);
    swap(n,m);
}
for(int i = 0;i < n;i++){
    mp1[a[i]]++;
}
for(int i = 0;i < m;i++){
    if(mp1[b[i]]) mp1[b[i]]--;
else mp2[b[i]]++;
}

int res = (m - n);
if(res % 2) res--;
int k = 0;

for(int i = 0;i < 26;i++){

    if(mp1['a' + i]){
        k += mp1['a' + i];
    }
}

for(int i = 0;i < 26;i++){
    if(mp2['a' + i] % 2 ) k++,mp2['a' + i]--;
    if(mp2['a' + i] >= 2 && res){
        if(res >= mp2['a' + i]){
            res -= mp2['a' + i];
            mp2['a' + i] = 0;
        }else{
            mp2['a' + i] -= res;
            res = 0;
            k += mp2['a' + i];
            mp2['a' + i] = 0;
        }
    }else k +=  mp2['a' + i];
}

if((n + m) % 2) k--;
cout << k / 2 << nl;


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
