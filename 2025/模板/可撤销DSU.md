```cpp
struct DSU {
vector<int> siz;
vector<int> f;
vector<array<int, 2>> his;
DSU(int n) : siz(n + 1, 1), f(n + 1) {
iota(f.begin(), f.end(), 0);
}
int find(int x) {
while (f[x] != x) {
x = f[x];
}
return x;
}
bool merge(int x, int y) {
x = find(x);
y = find(y);
if (x == y) {
return false;
}
if (siz[x] < siz[y]) {
swap(x, y);
}
his.push_back({x, y});
siz[x] += siz[y];
f[y] = x;
return true;
}
int time() {
return his.size();
}
void revert(int tm) {
while (his.size() > tm) {
auto [x, y] = his.back();
his.pop_back();
f[y] = y;
siz[x] -= siz[y];
}
}
};
```
