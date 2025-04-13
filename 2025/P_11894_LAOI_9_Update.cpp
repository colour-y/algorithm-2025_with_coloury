#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  int getans(int x,int k){
    if(x==1) return 1;
    while(k){
      int _2=log2(x),ne=1<<_2+1;  
      int dis=ne-x,to=ceil(dis*1.0/_2);
      if(k>=to) k-=to; 
      else to=k,k=0; 
      x+=_2*to;
    }
    return x;
  }


void solve(){
int n,m;
cin >> n >> m;
vector<int> a(n),b(n + 1,0);
for(auto &e : a){
    cin >> e;
}

while(m--){
  int x,y;
  cin >> x >> y;
  x--;
  b[x]++;
  b[y]--;
}

for(int i = 1;i <= n;i++){
b[i] += b[i - 1];
}


for(int i = 0;i < n;i++){
 
  cout << getans(a[i],b[i]) << " ";
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
