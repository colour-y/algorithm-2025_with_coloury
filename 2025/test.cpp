#include <iostream>
#include <cmath>
using namespace std;
int ans = 0;
void dfs(int n,int k){
if(n > 30 || k > 70) return;
if(k == 70) ans++;

dfs(n + 1,k + 10);
dfs(n + 1,k);
}

int main() {
dfs(0,0);
cout << ans ;
    return 0;
}
