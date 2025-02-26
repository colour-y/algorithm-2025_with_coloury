#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int n, m;
string s, forbiddenWords[110];
 
int main()
{
	cin >> n;
	cin.ignore();
 
	for (int i = 0; i < n; i++)getline(cin, forbiddenWords[i]);
	
	cin >> m;
	if (m == 0) cout << 0 << endl << "He Xie Ni Quan Jia!"; //如果阈值为0 无论输入如何都会违规
	else
	{
		cin.ignore();
		int cnt = 0;
		getline(cin, s);
		for (int i = 0; i < n; i++)
		{
			// 找到违禁词的位置，并用另一个词代替 
			while (s.find(forbiddenWords[i]) != s.npos)
			{
				int pos = s.find(forbiddenWords[i]);
				cnt++;
				s.erase(pos, forbiddenWords[i].length());
				s.insert(pos, "-_-");
			}
		}
		if (cnt >= m) cout << cnt << endl << "He Xie Ni Quan Jia!";
		else
		{
			// 找出违禁词的位置然后替换
			while (s.find("-_-") != -1)
			{
				int t = s.find("-_-");
				s.erase(t, 3);
				s.insert(t, "<censored>");
			}
			cout << s;
		}
	}
	return 0;
}
//https://blog.csdn.net/u012137663/article/details/138061341
//这题纯纯的煞笔md忍不了不想写了