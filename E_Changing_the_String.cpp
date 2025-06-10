#include <bits/stdc++.h>
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
int n,m,i,j;
cin >> n >> m;
vector a(3,vector<int>(3));
string s;
cin >> s;
int bc = 0,ba = 0,cb = 0 ,ca = 0,bca = 0,cba = 0;
while(m--){
    char s,t;
    cin >> s >> t;
    if(s != t && s != 'a'){
        if(t == 'a'){
            if(s == 'b'){
                if(cb == 0) ++ba;
                else ++cba,--cb;
            }else{
                if(bc == 0) ++ca;
                else ++bca,--bc;
            }
        }

        else if(s == 'b') ++bc;
        else ++cb;
    }
}

for(char &c : s)
if(c == 'b')
{
    if(ba) --ba,c = 'a';
    else if(cba) --cba,++cb, c = 'a';
else if(bca) --bca,c = 'a';
}
else if(c == 'c'){
    if(ca) --ca,c = 'a';
    else if(bca) --bca,++bc,c = 'a';
    else if(cba) --cba,c = 'a';
    else if(cb) -- cb,c = 'b';
}
cout << s << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
