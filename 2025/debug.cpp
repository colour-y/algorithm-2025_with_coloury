#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()

  static constexpr i64 mod=998244353;
  i64 qpow(i64 a,i64 b){
    i64 ans=1;
    while(b){
        if(b&1){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b=b>>1;
    }
    return ans;
}
    
void solve(){
  i64 n = 100000;
    auto dfs=[&](this auto &&dfs,int u,int s)->std::pair<int,int>{
        if(u<0){
            if(s==0){
                return {0,1};
            }
            return {1,1};
        }
        if(u==0){
            if(s==0){
                return {1,1};
            }
            return {0,1};
        }
        if(s==0){
            auto a=dfs(u-4,1);
            auto b=dfs(u-1,1);
            a.second*=2;
            b.second*=2;
            a.first=a.first*b.second+b.first*a.second;
            a.second*=b.second;
            i64 x=std::gcd(a.first,a.second);
            a.first/=x;
            a.second/=x;
            return a;
        }
        else{
            auto a=dfs(u-4,0);
            auto b=dfs(u-1,0);
            if((long double)a.first/a.second>(long double)b.first/b.second){
                return a;
            }
            else{
                return b;
            }
            return std::max(a,b);
        }
    };
    // auto x=dfs(103,0);
    // std::cout<<103<<" "<<x.first<<" "<<x.second<<" "<<(x.first*qpow(x.second,mod-2)%mod)<<endl;
    for(int i=1;i<=n;i++){
        auto x=dfs(i,0);
        std::cout<<i<<" "<<x.first<<" "<<x.second<<" "<<(x.first*qpow(x.second,mod-2)%mod)<<endl;
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
