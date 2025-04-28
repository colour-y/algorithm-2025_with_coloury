#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<array<int,26>> a(n+2);
    for(int c = 0; c < k; c++) {
        a[n][c] = a[n + 1][c] = n+1;
    }
    for(int i = n - 1; i >= 0; i--) {

        for(int c = 0; c < k; c++) 
            a[i][c] = a[i + 1][c];

        a[i][s[i]-'a'] = i+1;
    }


    vector<int> b(n + 2);
    b[n+1] = 1;  
    for(int i = n; i >= 1; i--) {
        int e = INT_MAX;
        for(int c = 0; c < k; c++) {
            int p = a[i - 1][c];
            int x = (p == n + 1 ? 1 : 1 + b[p + 1]);
            e = min(e, x);
        }
        b[i] = e;
    }

    int q;
    cin >> q;
    while(q--) {
        string t;
        cin >> t;
        int x = 1;
        auto ok = 0;
        for(char c : t) {
            int p = a[x - 1][c - 'a'];
            if(p == n + 1) {
                ok = 1;
                break;
            }
            x = p + 1;
        }
        if(ok) {
            cout << 0 << nl;
        } else {
            cout << b[x] << nl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
