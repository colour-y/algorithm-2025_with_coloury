#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
#define N 500005
struct node{
    int val,pos;
}a[N];
int n,s[N];
ll ans;
void change(int x, int k){
    while (x <= n) {
        s[x] += k;
        x += x & -x;
    }
}

int query(int x){
    int t = 0;
    while (x) {
        t += s[x];
        x -= x & -x;
    }
    return t;
}

int cmp(node x, node y){
    if (x.val == y.val) return x.pos > y.pos;
    else return x.val > y.val;
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].val;
        a[i].pos = i + 1;  // pos 从 1 开始
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++){
        ans += query(a[i].pos - 1);  // 统计逆序对
        change(a[i].pos, 1);         // 更新 Fenwick Tree
    }

    cout << ans << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
