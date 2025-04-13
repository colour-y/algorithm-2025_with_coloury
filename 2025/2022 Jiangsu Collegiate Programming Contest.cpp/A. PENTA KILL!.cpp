#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	map <string,set<string>> mp;
	for(int i=1;i<=n;i++) {
		string a;
		string b;
		cin >> a >> b;
		// mp[b].clear();
		if(mp[a].count(b)) {
			mp[a].clear();
		}
		mp[a].insert(b);
        
		if(mp[a].size() == 5) {
			cout << "PENTA KILL!\n";
			return;
		}

	}
	cout << "SAD:(\n";
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int _ = 1;
	// cin >> _;
	while(_--){
		solve();

	}
	return  0;
}