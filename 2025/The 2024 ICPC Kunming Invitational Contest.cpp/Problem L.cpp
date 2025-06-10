#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using B = bitset<2010>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(2 * m, vector<int>(n));
    vector<tuple<int, int, int, int>> R(2 * m);
    for (int i = 0; i < 2 * m; i++) {
        R[i] = {n, 1, -i, -0};
    }
    
    int q;
    cin >> q;
    vector<pair<int, int>> pos(q);

    vector<int> L(n + 1);
    L.back() = n;

    auto query = [&](int x) -> tuple<int, int, int, int> {
        tuple<int, int, int, int> res{0, 0, 0, 0};
        
        for (int i = n - 1; i >= 0; i--) {
            if (a[x][i]) {
                L[i] = 0;
            } else {
                L[i] = L[i + 1] + 1;
            }
        }

        int d = n;
        for (int i = 0; i < n; i++) {
            if (a[x][i]) {
                d = 0;
                continue;
            }
            d++;
            tuple<int, int, int, int> now{min({d, L[i], n}), !a[x ^ 1][i], -x, -i};
            res = max(res, now);
        }
        return res;
    };
    
    auto insert = [&]() -> pair<int, int> {
        tuple<int, int, int, int> res = *max_element(R.begin(), R.end());
        if (!get<0>(res)) {
            return {-2, -2};
        }

        int x = -get<2>(res), y = -get<3>(res);
        a[x][y] = 1;

        R[x] = query(x);
        R[x ^ 1] = query(x ^ 1);

        return {x, y};
    };

    auto erase = [&](pair<int, int> pos) -> void {
        auto [x, y] = pos;
        a[x][y] = 0;
        R[x] = query(x);
        R[x ^ 1] = query(x ^ 1);
    };

    while (q--) {
        int op, x;
        cin >> op >> x;
        x--;
        if (op == 1) {
            pos[x] = insert();
            cout << pos[x].first + 1 << ' ' << pos[x].second + 1 << '\n';
        } else {
            erase(pos[x]);
        }
    }

    return 0;
}