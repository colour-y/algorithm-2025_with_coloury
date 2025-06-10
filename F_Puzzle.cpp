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
int p,s;
cin >> p >> s;

int g = gcd(p,s);
p /= g;
s /= g;

for(int k = 1;;k++){
    if(k * ( 2 * s - p) < -2){
        cout << -1 << nl;
        return;
    }
    s *= k;
p *= k;

int e = (s * 4 - p);
if(e % 2){
    s /= k;
    p /= k;
    continue;
}

e /= 2;

int d = ceil(sqrt(s));

int mx = (s / d) * (d - 1) + (s / d - 1) * d + s % d + max(0,s % d - 1);
if(e < s - 1 || e > mx){
    s /= k;
    p /= k;
    continue;
}

int x = 0,y = 0;
cout << s << nl;
cout << 0 << " " << 0 << nl;
s--;
while(s != e)
{
    y++;
    if(y == d){
        x++;
        y = 0;
    }

    cout << x << " " << y << nl;
    s--;
    e -= (x > 0) + (y > 0);
}

while(s){
    x++;
    cout << x << " " << y << nl;
    s--;
}
return;
}



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

