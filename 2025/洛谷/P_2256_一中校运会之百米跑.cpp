#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  struct DSU
{
    vector<int> f, siz;
    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x)
    {
        return siz[find(x)];
    }
};

void solve(){
int n,m;
cin >> n >> m;
map<string,int> mp;
for(int i = 0;i < n;i++){
    string s;
    cin >> s;
    mp[s] = i;
}
DSU df(n + 1);
for(int i = 0;i < m;i++){
    string s1,s2;
    cin >> s1 >> s2;
    df.merge(mp[s1],mp[s2]);
}
int k;
cin >> k;
while(k--){
    string s1,s2;
    cin >> s1 >> s2;
    if(df.same(mp[s1],mp[s2])){
        cout << "Yes." << nl;
    }else{
        cout << "No." << nl;
    }
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
