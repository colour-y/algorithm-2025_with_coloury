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
    string s;
    cin >> n >> s;
   vector<pair<int,char>> a(3);
a[0].first = count(all(s),'T');
a[1].first = count(all(s),'I');
a[2].first = count(all(s),'L');
a[0].second = 'T';
a[1].second = 'I';
a[2].second = 'L';

if(a[0].first == a[1].first && a[1].first == a[2].first){
cout << 0 << nl;
return;
}
sort(all(a),greater());
int x = a[0].first ,y = a[1].first,z = a[2].first;
if((x == 0 && y == 0) || (x == 0 && z == 0 ) || (y == 0 && z == 0) ){
    cout << -1 << nl;
    return;
}

int e = 2 * x - y - z;

vector<int> cnt(n);
for(int i = 0;i < n;i++){
    if(s[i] == a[0].second) cnt[i] = 0;
    else if(s[i] == a[1].second) cnt[i] = 1;
    else cnt[i] = 2;
}
vector<int> ans;


//这里没有考虑到有一个为0的情况，因而wa了，在比赛的最后也没找到为什么，吃屎吃红温了


int i;
for( i = 0;i < n;i++){
    if((cnt[i] == 0 && cnt[i + 1] != 0) || (cnt[i] != 0 && cnt[i + 1] == 0)) break; 
}
i++;
int k = 0;
if(cnt[i - 1] == 0){
while(a[0].first > a[1].first){
ans.push_back(i);
ans.push_back(i);
k += 2;
a[1].first++;
a[2].first++;
}
}
else if(cnt[i] == 0){
    while(a[0].first > a[1].first){
        ans.push_back(i + k);
        ans.push_back(i + k + 1);
        k += 2;
        a[1].first++;
        a[2].first++;
        }
}
if(cnt[i] == 1){
    ans.push_back(i);
    k++;
}

for(;i < n;i++){
    if((cnt[i] == 0 && cnt[i + 1] == 1) || (cnt[i] == 1 && cnt[i + 1] == 0)){
        ans.push_back(i + 1 + k);
        k++;
    }
}


if(ans.size() < e)
{
    cout << -1 << nl;
    return;
}
else{
    cout << e << nl;
    for(i = 0;i < e;i++){
cout << ans[i] << nl;
    }
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
