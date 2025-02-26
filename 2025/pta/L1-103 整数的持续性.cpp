

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct node
{
  int x;
  int d;
} p[2000];


bool cmp(node a, node b)
{
  if (a.d == b.d)
    return a.x < b.x;
  return a.d > b.d;
}
int cnt, cntt;

void solve(int i)
{
  int j = 99;
  p[++cnt].x = i;
  cntt = 0;
  while (i > 9)
  {
    j = 1;
    while (i)
    {
      j *= i % 10;
      i /= 10;
    }
    cntt++;
    i = j;
  }
  p[cnt].d = cntt;
}
int main()
{
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; i++)
  {
    solve(i);
  }
  sort(p + 1, p + 1 + cnt, cmp);
  cout << p[1].d << endl;
  cout << p[1].x;
  for (int i = 2; i <= cnt; i++)
  {
    if (p[i].d == p[1].d)
      cout << " " << p[i].x;
  }
}