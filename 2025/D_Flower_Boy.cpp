
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<ll> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<ll> b(m+2);
        for(int i = 1; i <= m; i++) cin >> b[i];

        const int INF = n + 5;
        vector<int> l(m+2), r(m+2);

   
        l[0] = 0;
        for(int i = 1, j = 1; i <= m; i++){
            while(j <= n && a[j] < b[i]) j++;
            if(j > n) l[i] = INF;
            else { l[i] = j; j++; }
        }

     
        r[m+1] = n + 1;
        for(int i = m, j = n; i >= 1; i--){
            while(j >= 1 && a[j] < b[i]) j--;
            if(j < 1) r[i] = -INF;
            else { r[i] = j; j--; }
        }

        
        if(l[m] != INF){
            cout << 0 << '\n';
            continue;
        }

       
        ll ans = LLONG_MAX;
        for(int i = 1; i <= m; i++){
            if(l[i-1] < r[i+1]){
                ans = min(ans, b[i]);
            }
        }
        if(ans == LLONG_MAX) cout << -1;
        else cout << ans;
        cout << '\n';
    }
    return 0;
}
