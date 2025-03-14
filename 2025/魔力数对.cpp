#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class FenwickTree {
private:
    vector<int> data;
public:
    FenwickTree(int size) : data(size + 2, 0) {} // 使用size+2避免越界

    void update(int pos, int delta) {
        pos++; // 转换为1-based索引
        while (pos < data.size()) {
            data[pos] += delta;
            pos += pos & -pos;
        }
    }

    int query(int pos) {
        pos++; // 转换为1-based索引
        int res = 0;
        while (pos > 0) {
            res += data[pos];
            pos -= pos & -pos;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        ll L = sum - y;
        ll R = sum - x;

        vector<ll> tmp;
        for (ll num : a) {
            tmp.push_back(num);
        }
        for (int i = 0; i < n; ++i) {
            tmp.push_back(L - a[i]);
            tmp.push_back(R - a[i]);
        }

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        FenwickTree fenwick(tmp.size());

        ll ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ll current = a[i];
            ll low = L - current;
            ll high = R - current;

            int left = lower_bound(tmp.begin(), tmp.end(), low) - tmp.begin();
            int right = upper_bound(tmp.begin(), tmp.end(), high) - tmp.begin() - 1;

            if (left <= right) {
                int cnt = fenwick.query(right) - fenwick.query(left - 1);
                ans += cnt;
            }

            int pos = lower_bound(tmp.begin(), tmp.end(), current) - tmp.begin();
            fenwick.update(pos, 1);
        }

        cout << ans << '\n';
    }
    return 0;
}