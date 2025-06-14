#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()


template<class T>

constexpr T power(T a, i64 b) {

T res = 1;

for (; b; b /= 2, a *= a) {

if (b % 2) {

res *= a;

}

}

return res;

}

constexpr i64 mul(i64 a, i64 b, i64 p) {

i64 res = a * b - i64(1.L * a * b / p) * p;

res %= p;

if (res < 0) {

res += p;

}

return res;

}

template<i64 P>

struct MLong {

i64 x;

constexpr MLong() : x{} {}

constexpr MLong(i64 x) : x{norm(x % getMod())} {}

static i64 Mod;

constexpr static i64 getMod() {

if (P > 0) {

return P;

} else {

return Mod;

}

}

constexpr static void setMod(i64 Mod_) {

Mod = Mod_;

}

constexpr i64 norm(i64 x) const {

if (x < 0) {

x += getMod();

}

if (x >= getMod()) {

x -= getMod();

}

return x;

}

constexpr i64 val() const {

return x;

}

explicit constexpr operator i64() const {

return x;

}

constexpr MLong operator-() const {

MLong res;

res.x = norm(getMod() - x);

return res;

}

constexpr MLong inv() const {

assert(x != 0);

return power(*this, getMod() - 2);

}

constexpr MLong &operator*=(MLong rhs) & {

x = mul(x, rhs.x, getMod());

return *this;

}

constexpr MLong &operator+=(MLong rhs) & {

x = norm(x + rhs.x);

return *this;

}

constexpr MLong &operator-=(MLong rhs) & {

x = norm(x - rhs.x);

return *this;

}

constexpr MLong &operator/=(MLong rhs) & {

return *this *= rhs.inv();

}

friend constexpr MLong operator*(MLong lhs, MLong rhs) {

MLong res = lhs;

res *= rhs;

return res;

}

friend constexpr MLong operator+(MLong lhs, MLong rhs) {

MLong res = lhs;

res += rhs;

return res;

}

friend constexpr MLong operator-(MLong lhs, MLong rhs) {

MLong res = lhs;

res -= rhs;

return res;

}

friend constexpr MLong operator/(MLong lhs, MLong rhs) {

MLong res = lhs;

res /= rhs;

return res;

}

friend constexpr istream &operator>>(istream &is, MLong &a) {

i64 v;

is >> v;

a = MLong(v);

return is;

}

friend constexpr ostream &operator<<(ostream &os, const MLong &a) {

return os << a.val();

}

friend constexpr bool operator==(MLong lhs, MLong rhs) {

return lhs.val() == rhs.val();

}

friend constexpr bool operator!=(MLong lhs, MLong rhs) {

return lhs.val() != rhs.val();

}

};

template<>

i64 MLong<0LL>::Mod = i64(1E18) + 9;

template<int P>

struct MInt {

int x;

constexpr MInt() : x{} {}

constexpr MInt(i64 x) : x{norm(x % getMod())} {}

static int Mod;

constexpr static int getMod() {

if (P > 0) {

return P;

} else {

return Mod;

}

}

constexpr static void setMod(int Mod_) {

Mod = Mod_;

}

constexpr int norm(int x) const {

if (x < 0) {

x += getMod();

}

if (x >= getMod()) {

x -= getMod();

}

return x;

}

constexpr int val() const {

return x;

}

explicit constexpr operator int() const {

return x;

}

constexpr MInt operator-() const {

MInt res;

res.x = norm(getMod() - x);

return res;

}

constexpr MInt inv() const {

assert(x != 0);

return power(*this, getMod() - 2);

}

constexpr MInt &operator*=(MInt rhs) & {

x = 1LL * x * rhs.x % getMod();

return *this;

}

constexpr MInt &operator+=(MInt rhs) & {

x = norm(x + rhs.x);

return *this;

}

constexpr MInt &operator-=(MInt rhs) & {

x = norm(x - rhs.x);

return *this;

}

constexpr MInt &operator/=(MInt rhs) & {

return *this *= rhs.inv();

}

friend constexpr MInt operator*(MInt lhs, MInt rhs) {

MInt res = lhs;

res *= rhs;


return res;

}

friend constexpr MInt operator+(MInt lhs, MInt rhs) {

MInt res = lhs;

res += rhs;

return res;

}

friend constexpr MInt operator-(MInt lhs, MInt rhs) {

MInt res = lhs;

res -= rhs;

return res;

}

friend constexpr MInt operator/(MInt lhs, MInt rhs) {

MInt res = lhs;

res /= rhs;

return res;

}

friend constexpr istream &operator>>(istream &is, MInt &a) {

i64 v;

is >> v;

a = MInt(v);

return is;

}

friend constexpr ostream &operator<<(ostream &os, const MInt &a) {

return os << a.val();

}

friend constexpr bool operator==(MInt lhs, MInt rhs) {

return lhs.val() == rhs.val();

}

friend constexpr bool operator!=(MInt lhs, MInt rhs) {

return lhs.val() != rhs.val();

}

};

template<>

int MInt<0>::Mod = 998244353;

template<int V, int P>

constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1000000007;

using Z = MInt <P>;


void solve()
{
int n;
cin >> n;

vector<vector<int>> adj(n);
vector<int> p(n);
for(int i = 1;i < n;i++){
  int u,v;
  cin >> u >> v;
  u--,v--;

  adj[u].push_back(v);
  adj[v].push_back(u);
}

vector<int> dep(n);
auto dfs = [&](this auto&& self,int x)-> void{
  for(auto y : adj[x]){
    if(y == p[x]){
      continue;
    }

    p[y] = x;
    dep[y] = dep[x] + 1;
    self(y);
  }
};
p[0] = -1;
dfs(0);
vector<int> leaf;
for(int i = 1;i < n;i++){
  if(adj[i].size() == 1){
    leaf.push_back(i);
  }
}
Z ans = 0;
if(leaf.size() > 2){
  ans = 0;
}else if(leaf.size() == 2){
  int x = 0;
  while(adj[x].size() - (x > 0) < 2)
  {
    x++;
  }
  int a = dep[leaf[0]] - dep[x];
  int b = dep[leaf[1]] - dep[x];
  if(a > b){
    swap(a,b);
  }

  if(a == b){
    ans = power(Z(2),dep[x] + 2);

  }else{
    ans = power(Z(2),dep[x] + b - a) * 3;
  }
}else{
  ans = power(Z(2),n);
}
cout << ans << nl;
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

