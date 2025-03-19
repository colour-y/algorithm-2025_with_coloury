#include<bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
using i64 = long long;
using u32 = unsigned;

mt19937_64 rnd(random_device{}());

const int mod = 998244353;
const int N = 1e6 + 5;
const int M = 3e5 + 5;

void solve(int tc)
{
	int n;
	cin >> n;
	
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<bool> ok(N);
	vector<bool> ex(N);
	
	set<int> st;
	
	int L = 0;
	
	vector<int> prefix(n + 1);
	for(int i = 1; i <= n; i++) {
		if(a[i] == 0) {
			while(L < i) {
				ok[a[L]] = 1;
				//cout << "!" << a[i] << '\n';
				L += 1;
			}
		} else {
			if(ok[a[i]]) {
				st.insert(a[i]);
			}
		}
		prefix[i] = st.size();
	} 
	
	//cout << "@" << st.size() << '\n';
	
	i64 ans = 0;
	
	for(int i = n; i >= 4; i--) {
		if(ex[a[i]] || a[i] == 0) continue;
		ans += prefix[i - 1];
		//cout << ans << '\n';
		ex[a[i]] = 1;
	}
	
	cout << ans << '\n';
}

signed main()
{ 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T = 1;
	cin >> T;

	for(int tc = 1; tc <= T; tc++) {
	   solve(tc);
	}

	return 0;
}