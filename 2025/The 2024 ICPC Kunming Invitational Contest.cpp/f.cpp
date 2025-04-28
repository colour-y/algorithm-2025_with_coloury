#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
struct node{
    int s,c;
    bool operator <(const node &o )const{
        return s<o.s;
    }
}f[1000001];
struct node{
    int sum,v;
}a,b;
int n,flag,l,r,res,v1,v2;
bool check(int v){
    v1=v2=0;
    for(int i=1;i<=n;i++){
        if(!v1){
            v1=1;
            a.v=f[i].c;
        }
        if(v1){
            if(f[i].s-f[i-1].s)
            if(!v2){
              v2=1;
               b.sum=0;
           }else{
                
           }
        }
        
        
    }
}
void solve(){
    cin>>n;
    l=1,r=1000000000;res=-1;
    for(int i=1;i<=n;i++){
        cin>>f[i].s>>f[i].c;
    }
    sort(f+1,f+n+1);
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            r=mid-1;
            res=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<mid<<endl;
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