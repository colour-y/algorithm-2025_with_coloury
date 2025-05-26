#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const int MAXN = 2000000;
static int visStamp[MAXN+5];
static int curStamp = 1;
static vector<int> primes;

// 预处理小于 sqrt(MAXN) 的素数
void init_primes() {
    int limit = 1500; // sqrt(2e6) ~1414
    vector<bool> isprime(limit+1,true);
    isprime[0]=isprime[1]=false;
    for (int i=2; i<=limit; ++i) {
        if(isprime[i]) {
            primes.push_back(i);
            if ((ll)i*i <= limit) {
                for (int j=i*i; j<=limit; j+=i) isprime[j] = false;
            }
        }
    }
}

// 求 n 的所有因子
vector<ll> get_divisors(ll n) {
    vector<pair<ll,int>> fac;
    ll temp = n;
    for (int p: primes) {
        if ((ll)p*p > temp) break;
        if (temp % p == 0) {
            int cnt=0;
            while (temp % p == 0) {
                temp /= p;
                cnt++;
            }
            fac.emplace_back(p, cnt);
        }
    }
    if (temp > 1) fac.emplace_back(temp,1);
    vector<ll> divisors = {1};
    for (auto &pr: fac) {
        ll prime = pr.first;
        int cnt = pr.second;
        int sz = divisors.size();
        ll mul = 1;
        for (int c = 1; c <= cnt; ++c) {
            mul *= prime;
            for (int i = 0; i < sz; ++i) {
                divisors.push_back(divisors[i] * mul);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

// 前向 BFS，阈值参数用于限制搜索范围
int bfs_forward_with_thr(ll x, ll y, ll k, ll threshold) {
    curStamp++;
    if (curStamp == 0) {
        curStamp = 1;
        memset(visStamp, 0, sizeof(visStamp));
    }
    deque<pair<ll,int>> dq;
    if (x <= threshold) {
        visStamp[x] = curStamp;
        dq.emplace_back(x, 0);
    }
    while (!dq.empty()) {
        auto [u, d] = dq.front(); dq.pop_front();
        if (u == y) return d;
        // 操作1：x = x * a
        for (ll a = 2; a <= k; ++a) {
            if (u > threshold / a) break;
            ll v = u * a;
            if (v > threshold) break;
            if (v == y) return d + 1;
            if (visStamp[v] != curStamp) {
                visStamp[v] = curStamp;
                dq.emplace_back(v, d+1);
            }
        }
        // 操作2：如果 u = b^a，则 x = b
        if (u > 1) {
            int maxA = 63 - __builtin_clzll(u);
            if (maxA > k) maxA = k;
            for (int a = 2; a <= maxA; ++a) {
                double pf = pow((double)u, 1.0 / a);
                ll b = (ll)floor(pf);
                if (b < 1) break;
                if (b > 1) {
                    ll vcalc = 1;
                    for (int i = 0; i < a; ++i) {
                        if (vcalc > u / b) { vcalc = LLONG_MAX; break; }
                        vcalc *= b;
                    }
                    if (vcalc == u) {
                        ll v = b;
                        if (v == y) return d + 1;
                        if (visStamp[v] != curStamp) {
                            visStamp[v] = curStamp;
                            dq.emplace_back(v, d+1);
                        }
                    }
                    ll b1 = b + 1;
                    ll vcalc2 = 1;
                    for (int i = 0; i < a; ++i) {
                        if (vcalc2 > u / b1) { vcalc2 = LLONG_MAX; break; }
                        vcalc2 *= b1;
                    }
                    if (vcalc2 == u) {
                        ll v = b1;
                        if (v == y) return d + 1;
                        if (visStamp[v] != curStamp) {
                            visStamp[v] = curStamp;
                            dq.emplace_back(v, d+1);
                        }
                    }
                } else {
                    ll b1 = 2;
                    ll vcalc2 = 1;
                    for (int i = 0; i < a; ++i) {
                        if (vcalc2 > u / b1) { vcalc2 = LLONG_MAX; break; }
                        vcalc2 *= b1;
                    }
                    if (vcalc2 == u) {
                        ll v = b1;
                        if (v == y) return d + 1;
                        if (visStamp[v] != curStamp) {
                            visStamp[v] = curStamp;
                            dq.emplace_back(v, d+1);
                        }
                    }
                }
            }
        }
    }
    return -1;
}

// 逆向 BFS，阈值参数用于限制搜索范围
int bfs_backward_with_thr(ll x, ll y, ll k, ll threshold) {
    curStamp++;
    if (curStamp == 0) {
        curStamp = 1;
        memset(visStamp, 0, sizeof(visStamp));
    }
    deque<pair<ll,int>> dq;
    if (y <= threshold) {
        visStamp[y] = curStamp;
        dq.emplace_back(y, 0);
    }
    while (!dq.empty()) {
        auto [u, d] = dq.front(); dq.pop_front();
        if (u == x) return d;
        // 逆操作1：如果 c % a == 0，则可能之前是 c/a
        if (u > 1) {
            ll temp = u;
            vector<pair<ll,int>> fac;
            for (int p: primes) {
                if ((ll)p*p > temp) break;
                if (temp % p == 0) {
                    int cnt=0;
                    while (temp % p == 0) {
                        temp /= p;
                        cnt++;
                    }
                    fac.emplace_back(p, cnt);
                }
            }
            if (temp > 1) fac.emplace_back(temp,1);
            vector<ll> divisors = {1};
            for (auto &pr: fac) {
                ll prime = pr.first;
                int cnt = pr.second;
                int sz = divisors.size();
                ll mul = 1;
                for (int c = 1; c <= cnt; ++c) {
                    mul *= prime;
                    for (int i = 0; i < sz; ++i) {
                        divisors.push_back(divisors[i] * mul);
                    }
                }
            }
            for (ll dval: divisors) {
                if (dval < 2) continue;
                if (dval <= k) {
                    ll prev = u / dval;
                    if (prev == x) return d + 1;
                    if (prev <= threshold && visStamp[prev] != curStamp) {
                        visStamp[prev] = curStamp;
                        dq.emplace_back(prev, d+1);
                    }
                }
                ll other = u / dval;
                if (other >= 2 && other <= k) {
                    ll prev = dval;
                    if (prev == x) return d + 1;
                    if (prev <= threshold && visStamp[prev] != curStamp) {
                        visStamp[prev] = curStamp;
                        dq.emplace_back(prev, d+1);
                    }
                }
            }
        }
        // 逆操作2：c = prev^a
        if (u > 1) {
            ll maxA = k;
            if (u > 1) {
                double maxAd = floor(log((double)threshold) / log((double)u));
                if (maxAd < (double)maxA) maxA = (ll)maxAd;
            }
            for (ll a = 2; a <= maxA; ++a) {
                ll vcalc = 1;
                bool overflow=false;
                for (int i = 0; i < a; ++i) {
                    if (vcalc > LLONG_MAX / u) { overflow=true; break; }
                    vcalc *= u;
                    if (vcalc > threshold) { overflow=true; break; }
                }
                if (overflow) break;
                ll prev = vcalc;
                if (prev == x) return d + 1;
                if (visStamp[prev] != curStamp) {
                    visStamp[prev] = curStamp;
                    dq.emplace_back(prev, d+1);
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_primes();
    int t;
    cin >> t;
    while (t--) {
        ll x, y, k;
        cin >> x >> y >> k;
        if (x == y) {
            cout << 0 << '\n';
            continue;
        }
        // 特殊情况：x=1，只能通过乘法操作到 y
        if (x == 1) {
            if (y == 1) {
                cout << 0 << '\n';
                continue;
            }
            if (y <= k) {
                cout << 1 << '\n';
                continue;
            }
            // 在 y 的因子集合上做 BFS
            vector<ll> divs = get_divisors(y);
            unordered_map<ll,int> dist;
            queue<ll> q;
            dist[1] = 0;
            q.push(1);
            int ans = -1;
            while (!q.empty()) {
                ll u = q.front(); q.pop();
                int d = dist[u];
                for (ll v: divs) {
                    if (v < u) continue;
                    if (v % u != 0) continue;
                    ll a = v / u;
                    if (a >= 2 && a <= k) {
                        if (!dist.count(v)) {
                            dist[v] = d + 1;
                            if (v == y) {
                                ans = d + 1;
                                break;
                            }
                            q.push(v);
                        }
                    }
                }
                if (ans != -1) break;
            }
            cout << ans << '\n';
            continue;
        }
        int ans = -1;
        if (x <= y) {
            // 前向 BFS 限制在 2*max(x,y)
            ll threshold = 2LL * max(x, y);
            if (threshold > MAXN) threshold = MAXN;
            ans = bfs_forward_with_thr(x, y, k, threshold);
            if (ans < 0) {
                // 如果失败，则逆向 BFS 全局搜索
                ans = bfs_backward_with_thr(x, y, k, MAXN);
            }
        } else {
            // 逆向 BFS 限制在 min(MAXN, x*k)
            ll threshold = x * k;
            if (threshold > MAXN) threshold = MAXN;
            ans = bfs_backward_with_thr(x, y, k, threshold);
            if (ans < 0) {
                // 如果失败，则前向 BFS 全局搜索
                ans = bfs_forward_with_thr(x, y, k, MAXN);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
