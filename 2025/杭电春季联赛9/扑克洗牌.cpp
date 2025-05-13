#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+1), pos(n+1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            pos[a[i]] = i;
        }

        int best = 1, cur = 1;
      
        for (int v = 2; v <= n; v++){
            if (pos[v] > pos[v-1]) {
                cur++;
            } else {
                cur = 1;
            }
            best = max(best, cur);
        }

      
        cout << (n - best) << "\n";
    }

    return 0;
}
