#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int n, A[N], B[N], X[N], Y[N], id[N];
int stk[N], top=0;
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i){
        cin >> A[i] >> B[i];
        X[i] = A[i]-i; Y[i] = i-B[i];
        id[i] = i;
    }
    sort(id+1, id+n+1, [&](int a, int b){return X[a]!=X[b] ? X[a]<X[b] : Y[a]<Y[b];});

    int cur=id[1];
    for (int i=2; i<=n; ++i){
        if (Y[id[i]] >= Y[cur]){
            while (top>0 && Y[id[i]] >= Y[stk[top]]) --top;
        }else{
            if (X[cur]!=X[id[i]]) stk[++top] = cur;
            cur = id[i];
        }
    }
    stk[++top] = cur;
    cout << top << '\n';

    return 0;
}
