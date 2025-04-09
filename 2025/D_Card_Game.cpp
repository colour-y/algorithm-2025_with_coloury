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
int n;
cin >> n;
ll a,b;
cin >> a >> b;
int m = n;
ll xx = a,yy = b;
vector<ll> p,q(n);

int k = 0;
for(int  i = 0;i < n;i++){
    ll x;
    cin >> x;
    if(x == -1)
    {
        k++;
    }else{
        p.push_back(x);
    }
// tes.push_back(x);
}


for(auto &e : q)
{
    cin >> e;
}

sort(all(p),greater());

if(p.size() == 0){
    cout << "no" << nl;
    return;
}
priority_queue<ll> pq;
priority_queue<ll, std::vector<ll>, std::greater<>> s;

int r = 0;

int io = 0;
for(auto e : q){

if(e == -1){ 
   io++;
    continue;
}else{
    io++;
    a -= e;
    pq.emplace(e);

}


if(a <= 0  && !s.empty()){
    while(1){
    ll x = s.top();
    s.pop();
    pq.emplace(x);
    ll y = pq.top();
    pq.pop();
    a -= x;
    a += y;
    s.emplace(y);
    
if(x == y) break;
}
}

ll v = a;


while(a <= 0 && k &&!pq.empty()){
    
ll x = pq.top();
pq.pop();
s.emplace(x);
a += x;
k--;
}

if(v == a){
    b -= p[r++];
}



if(a > 0 && b <= 0 ){
    cout << "yes" << nl;
    return;
} 

if( a <= 0){

    cout << "no" << nl;
    return;
}



if(r == p.size() && b > 0){
   
    cout << "no" << nl;
    return;
}

// cout << a << " " << b << nl;
cout << a << " " << b << nl;
}

cout << "no" << nl;
}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t = 1;
cin >> t;
// ll e = t;
while(t--){
    solve();
}
    return 0;
}
