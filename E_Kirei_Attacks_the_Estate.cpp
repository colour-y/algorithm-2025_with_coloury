#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i = 0, x, y; i < n-1; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> p(n+1, 0), e;
   
    queue<int> q;

    q.push(1);
    p[1] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        e.push_back(x);
        for(int c : adj[x]){
            if(c == p[x]) continue;
            p[c] = x;
            q.push(c);
        }
    }

    vector<array<ll,2>> dp(n+1, {0,0});
    dp[1][0] = a[1];
    dp[1][1] = -a[1];

    for(int i = 1; i < n; i++){
        int x = e[i];
        int y = p[x];
        dp[x][0] = a[x] + max(0LL, dp[y][1]);
        dp[x][1] = -a[x] + max(0LL, dp[y][0]);
    }

    for(int i = 1; i <= n; i++){
        cout << dp[i][0] << " ";
    }

    cout << nl;
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
