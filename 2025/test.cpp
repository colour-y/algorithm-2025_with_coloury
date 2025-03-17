#include<bits/stdc++.h>
using namespace std;

const char nl = '\n';

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	if (t == 1) {
		int k = 1;

	}
	char O;  //记录当前操作符
	while (t--) {
		string s;
		cin >> s;
		int n = 0, m = 0;
		if ('a' <= s[0] && s[0] <= 'c') {
			O = s[0];
			cin >> n >> m;
		}
		else {
			for (int i = 0; i < s.length(); i++) {
				n *= 10;
				n += s[i] - '0';
			}
			scanf("%d", &m);
		}
		long r;
		if (O == 'a') {
			r = n + m;
			cout << n + m << nl;
		}
		else if (O == 'b') {
			r = n - m;
			printf("%d-%d=%d\n", n, m, n - m);
		}
		else {
			r = n * m;
			printf("%d*%d=%ld\n", n, m, n * m);   //10e5 * 10e5 = 10e10 ~ 2e33
		}
		int len = 2;
		
		//若是输入的两个数是0
		if (n == 0) {
			len++;
		}
		else {
			while (n) {
				len++;
				n /= 10;
			}
		}
		if (m == 0) {
			len++;
		}
		else {
			while (m) {
				len++;
				m /= 10;
			}
		}
		//运算结果是负数的时候有个负号,所以也要++
		if (r < 0) {
			len++;
		}
		//当r>=0时，等于0和大于0要分开写
		if (r == 0) {
			len++;
		}
		else {
			while (r) {
				len++;
				r /= 10;
			}
		}
		cout << len << nl;
	}

	return 0;
}