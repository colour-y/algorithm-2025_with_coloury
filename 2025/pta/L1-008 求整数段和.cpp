#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int a,b;
cin >> a >> b;
int sum = 0;
int k = 0;
for(int i = a;i <= b;i++){
    printf("%5d",i);
    k++;
    if( k % 5 == 0 && B - A != 4)	printf("\n");
    sum += i;
}

printf("\nSum = %d",sum);
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;

while(t--){
    solve();
}
    return 0;
}
