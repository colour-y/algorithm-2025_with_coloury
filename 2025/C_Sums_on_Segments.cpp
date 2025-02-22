#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
void solve(){
int n;
cin >> n;
vector<int> a(n);
int x = 0;
for(int i = 0;i < n;i++){
    cin >> a[i];
}
while(x < n && abs(a[x]) == 1){
    x++;
}

vector<int> ans;
  {
        int mins = 0, maxs = 0;
        int s = 0, S = 0;
        for (int i = 0; i < x; i++) {
            s =min(0, s + a[i]);
            S = max(0, S + a[i]);
            mins = min(s, mins);
            maxs = max(S, maxs);
        }
        
        for (int i = mins; i <= maxs; i++) {
            ans.push_back(i);
        }
    }

if(x < n){
  {  
    int mins = 0,maxs = 0;
    int s = 0,S = 0;
    for(int i = x + 1;i < n;i++){
        s = min(0,s + a[i]);
        S = max(0,S + a[i]);
        mins = min(s,mins);
        maxs = max(S,maxs);
    }

   for(int i = mins;i <= maxs;i++){
    ans.push_back(i);
   }
}
   int lmin = 0,lmax = 0;
   int rmin = 0,rmax = 0;
   int s = 0;
   for(int i = x - 1;i >= 0;i--){
    s += a[i];
    lmin = min(lmin,s);
    lmax = max(lmax,s);
   }
   s = 0;
   for(int i =  x + 1;i < n;i++){
    s += a[i];
   rmin = min(rmin,s);
   rmax = max(rmax,s);
   }
   for(int i = lmin + rmin;i <= lmax + rmax;i++){
    ans.push_back(a[x] + i);
   }
}
ranges::sort(ans);
ans.erase(unique(ans.begin(),ans.end()),ans.end());

cout << ans.size() << nl;
for(int i = 0;i < ans.size();i++){
    cout << ans[i] << " \n"[i == ans.size() - 1];
}

}


int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int t;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
