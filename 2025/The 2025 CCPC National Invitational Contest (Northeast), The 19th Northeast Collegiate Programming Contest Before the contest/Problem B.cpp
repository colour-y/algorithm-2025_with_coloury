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
int n,k;
cin >> n >> k;
vector<int> a(n);
for(auto &e : a){
    cin >> e;
}
vector<int> e;
int c = a[n - 1];
e.push_back(c);
for(int i = n - 2;i >= 0;i--){
if(a[i] < c && k){
    k--;
}
else{
    c = a[i];
e.push_back(c);
}
}


if(k){
   k = min(k, 2 * int(e.size() - 1));
    int x = e.back();
    e.pop_back();
    while(k > 1){
        e.pop_back();
        k -= 2;
    }
    e.push_back(x);

// if(e.size() == 1){
//     cout << 1 << nl << e[0] << nl;
//     return;
// }


    if(k){
        swap(e.end()[-1],e.end()[-2]);
        if(*max_element(all(a)) != a[0])
        e.back() = min(e.back(),a[0]);

    }

}



reverse(all(e));

cout << e.size() << nl;
for(auto f : e){
    cout << f << " ";
}

}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
// cin >> t;
while(t--){
    solve();
}
    return 0;
}

