#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll K;
    if (!(cin >> n >> K)) return 0;

    vector<ll> score(n);
    for (ll &x : score) cin >> x;

    /* -------------------------------------------------
       1. 先按分数排序，保存原下标。                     */
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](int a, int b) { return score[a] < score[b]; });

    /* -------------------------------------------------
       2. 贪心配对：queue 里永远是“待配的小分”            */
    deque<int> q;
    vector<int> order; order.reserve(n);

    for (int id : idx) {
        if (!q.empty() && score[id] > score[q.front()] + K) {
            order.push_back(q.front());      // 小的先出场（不一定通过）
            order.push_back(id);             // 大的紧跟其后，一定通过
            q.pop_front();
        } else {
            q.push_back(id);                 // 先存起来，等更大的来配
        }
    }
    /* 剩下没人能再配成对的，直接照原来顺序塞进去 */
    while (!q.empty()) {
        order.push_back(q.front());
        q.pop_front();
    }

    /* -------------------------------------------------
       3. 再跑一遍模拟统计真正通过的人数                  */
    int passed = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || score[order[i]] > score[order[i - 1]] + K)
            ++passed;
    }

    /* -------------------------------------------------
       4. 输出                                           */
    cout << passed << '\n';
    for (int i = 0; i < n; ++i) {
        cout << order[i] + 1 << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
