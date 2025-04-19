#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n;
	std::cin >> n;
	std::vector e(n + 1, std::vector<int > ());
	i64 sum = 0;
	std::unordered_map<int, std::unordered_map<int, i64>> mp;
	for (int i = 0; i < n - 1; i++) {
		int u, v, p, q;
		std::cin >> u >> v >> p >> q;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
		mp[u][v] = p;
		mp[v][u] = q;
	}
	std::vector<int> par(n + 1, 0);
	int s, t;
	std::cin >> s >> t;
	std::vector<int> vis(n + 1, 0);
	auto dfs = [&](auto && self, int u, int fu)->void{
		par[u] = fu;
		if (u == t) {
			int x = u;
			while (x != 0) {
				vis[x] = 1;
				x = par[x];
			}
		}
		for (auto v : e[u]) {
			if (v == fu) {
				continue;
			}
			self(self, v, u);
		}
	};
	dfs(dfs, s, 0);
	i64 ans = 0;
	auto dfs1 = [&](auto && self, int u, int fu)->i64{
		i64 sum = 0;
		for (auto v : e[u]) {
			if (v == fu) {
				continue;
			}
			if (vis[v] == 1) {
				sum += mp[u][v] + self(self, v, u);
			}
			else {
				sum += std::max(0ll, mp[u][v] + mp[v][u] + self(self, v, u));
			}

		}
		return sum;
	};
	std::cout << (dfs1(dfs1, s, 0)) << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}