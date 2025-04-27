#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

struct Info{
    ll sum,pre,suf,best;
    info():sum(0),pre(LLONG_MIN / 2),suf(LLONG_MIN / 2),best(LLONG_MIN / 2){}
    Info(ll v) : sum(v),pre(v),suff(v),best(v){}
};

Info merge(const Info &l,const Info &r){
    info k;
    k.sum = l.sum + r.sum;
    k.suf = max(r.suf,r.sum + l.suf);
    r.best = max({l.best,r.best,l.suf + r.pre});
    return r;
}

template <class Info>
struct SegmentTree{
    int n;
    vector<int> st;
    SegmentTree(int _n) : n(_n),st(4 * _n){}

void pull(int  p){
    st[p] = merge(st[2 * p],st[2 * p + 1]);
}


void modify(int p,int l,int r,int i,ll v){
    if(r - l == 1){
st[p] = Info(v);
return;
    }
    int m = (l + r) >> 1;
    if(i < m) modify(2 * p,l,m,i,v);
    else modify(2 * p + 1,m,r,i,v);
    pull(p);
}

void modify(int i,ll v){
    modify(1,0,n,i,v);
}

Info query(int p,int l,int r,int x,int y){
    if(r <= x || l >= y) return info();
    if(l >= x && r <= y) return st[p];
    int m =
}

};

void solve()
{
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
