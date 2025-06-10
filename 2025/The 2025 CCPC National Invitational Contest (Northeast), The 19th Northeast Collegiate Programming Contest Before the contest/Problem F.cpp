#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

void solve()
{
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
auto check = [&](int x,int y) -> double{
double s = 0.5 * y + x * 30;
double f = y * 6;
double s1 = 0.5 * y1 + x1 * 30;
double f1 = y1 * 6;

s1 = abs(s1 - s);
s1 = min(s1,360.0 - s1);
f1 = abs(f1 - f);
f1 = min(f1,360.0 - f1);
return f1 + s1;
};

auto time = [&](auto x,auto y) ->int{
    return 60 * x + y;
};

double sum = 1e9 + 7;

int ans = 0,res = 0;
while(1){
    if(time(x2,y2) > time(x3,y3)) break;

    if(check(x2,y2) < sum)
    {
        sum = check(x2,y2);
        ans = x2;
res = y2;
    }
    y2++;
    if(y2 == 60)
    {
        x2++;
y2 = 0;
    }
}
cout << ans << " " << res << nl;


}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
cin >> t;
while(t--){
    solve();
}
    return 0;
}

