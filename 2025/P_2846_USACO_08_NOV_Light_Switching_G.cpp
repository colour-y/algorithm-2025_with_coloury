#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  struct Info {
    int count;
    Info operator+(const Info &other) const {
        return Info(count + other.count);
    }
};

template<class Info>
struct SegmentTree
{
  int n;
  vector<int> tag;
  vector<Info> info;
  SegmentTree(int n_) : n(n_),tag(4 * n),info(4 * n){}

  void pull(int p){
    info[p] = info[2 * p] + info[2 * p + 1];

  }

void add(int p,int v,int len){
  if(v % 2){
    info[p].count = len - info[p].count;
    tag[p] ^= v;

  }
}

void push(int p,int l,int r){
  if(tag[p]){
    int m = (l + r) / 2;
    add(2 * p,tag[p],m -l);
    add(2 * p + 1,tag[p],r - m);
    tag[p] = 0;
  }
}

Info query(int p,int l,int r,int x,int y){
  if(l >= y || r <= x ) return Info();
  if(l >= x && r <= y ) return info[p];
  int m = (l + r) / 2;
  push(p,l,r);
  return query(2 * p,l,m,x,y) + query(2 * p + 1,m,r,x,y);

}

Info query(int x,int y){
  return query(1,0,n,x,y);

}


void rangeAdd(int p, int l, int r, int x, int y, int v) {
  if (l >= y || r <= x) return;
  if (l >= x && r <= y) {
      add(p, v, r - l);
      return;
  }
  int m = (l + r) / 2;
  push(p, l, r);
  rangeAdd(2 * p, l, m, x, y, v);
  rangeAdd(2 * p + 1, m, r, x, y, v);
  pull(p);
}

void rangeAdd(int x, int y, int v) {
  rangeAdd(1, 0, n, x, y, v);
}
};


void solve(){
int n,m;
cin >> n >> m;
SegmentTree<Info> seg(n + 1);
while(m--){
  int k,x,y;
  cin >> k >> x >> y;
  if(k == 0){
    seg.rangeAdd(x,y + 1,1);

  }else{
   auto res = seg.query(x,y + 1);
   cout << res.count << nl;
  }
}
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}
