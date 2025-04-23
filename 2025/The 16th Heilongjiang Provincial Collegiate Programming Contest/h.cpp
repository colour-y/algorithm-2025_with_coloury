#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int parent[MAXN];
long long counter = 0;
typedef long long ll;
ll ans = 0;
int find(int x)
{
    while (x != parent[x])
    {
        if (x < parent[x])
        {
            // Merge-by-rank and Path-compression
            parent[x] = parent[parent[x]];
            
        }
        ans++;
        x = parent[x];
        counter++;
       
    }
    return x;
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    parent[a] = b;
}
int main()
{
    int n,m;
    cin >> n >> m;
for(int i = 1;i <= n - 1;i++){
    cout << n << " " << n - i << '\n';
}
cout << n << " " << n << '\n';
    return 0;
}