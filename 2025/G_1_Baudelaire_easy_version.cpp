#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';
  typedef long long ll;
  typedef long double ld;
using i64 = unsigned long long;
using i32 = unsigned;
using i128 = unsigned __int128;
  #define all(x) (x).begin(), (x).end()
  #define All(x) (x).begin() + 1, (x).end()


template<typename T>
void out(T x, T y){
    for(;x != y;x++){
        cout << *x << ' ';
      
    }
    cout << endl;
}

int query1(int n,vector<int> v){
    cout << "? 1 " << n << " ";
    out(all(v));
    int x;
    cin >> x;
    return x; 
}

void query2(int x){
    cout << "? 2 " << x << endl;
}

void solve(){
int n;
cin >> n;

vector<int> ans(n + 1);
for(int i = 1 ;i < n;i++){
    int x,y;
    cin >> x >> y;
}

auto bs = [&](){
    query2(1);
    int l = 2,r = n;


    while(l < r){
        int mid = (l + r) >> 1;
        vector<int> q;
        ll sum = 0;
        for(int i = l;i <= mid;i++){
            q.push_back(i);
            sum += ans[i];
        }
        int k = query1(q.size(),q);

        if(sum != k)
         r = mid;
         else l = mid + 1;
    }
    query2(1);
    ans[l] = query1(1,{l});
};


int x = query1(1,{1});
if(x == 1 || x == -1){
    ans[1] = x;
    for(int i = 2;i <= n;i++)
        ans[i] = query1(1,{i}) - x;

        cout << "! ";
        out(All(ans));
// cout << 1111111111111111 << endl;
    }else{
        if(x == 0){
            query2(1);
            int y = query1(1,{1});
            ans[1] = y / 2;
            for(int i = 2;i <= n;i++) ans[i] = query1(1,{i}) - y;
            bs();
            cout << "! ";
            out(All(ans));
          
        }else{
            ans[1] = x / 2;
            for(int i = 2;i <= n;i++){
                ans[i] = query1(1,{i}) - x;

            }
            bs();
            cout << "! ";
            out(All(ans));
        }
        // cout << 1111111111111111 << endl;
    }


}



int main(){
ios::sync_with_stdio(0),cin.tie(0);
int t = 1;
cin >> t;
while(t--){
    solve();
}
    return 0;
}
