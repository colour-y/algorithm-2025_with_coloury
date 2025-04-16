#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define deb(...) 114514
#endif

const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n;
ll x;
cin >> n >> x;
vector<ll> a(n);
for(auto &e : a){
    cin >> e;
}

vector<ll> sum(n + 1);
for(int i = 1;i <= n;i++){
    sum[i] += sum[i - 1] + (i != n ? abs(a[i] - a[i - 1]) : 0);

}

if(sum[n] <= x){
    cout << 0 << nl;
    return;
}

auto check = [&](int len) -> bool {
        deque<int> que;
        for (int i = 0; i < len; i++) {
            while (que.size() && a[i] >= a[que.back()]) {
                que.pop_back();
            }
            que.push_back(i);
        }
        for (int l = 0, r = len; r <= n; l++, r++) {
            ll res = 0;
            if (l != 0) {
                res += abs(a[l - 1] - a[que.front()]);
                res += sum[l - 1];
            }
            if (r < n) {
                res += abs(a[r] - a[que.front()]);
                res += sum[n] - sum[r];
            }
            if (res <= x)
                return true;
            if (que.front() == l) {
                que.pop_front();
            }
            if (r < n) {
                while (que.size() && a[r] >= a[que.back()]) {
                    que.pop_back();
                }
                que.push_back(r);
            }
        }
        return false;
    };
  deb(check(n));
int l = 2,r = n;
while(l < r){
    int mid = (l + r) >> 1;
    if(check(mid)){
        r = mid;
    }else{
        l = mid + 1;
    }
}
cout << l << nl;


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
