/*
  ~ Akshat Gupta ~
*/
#include <bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define TEST(t) int t; cin>>t; while(t--) 
#define mod 10000007
using namespace std;
signed main()
{
    fastIO;
    TEST(t)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int mini=1e18;
        for(int i=0;i<n;)
        {
            int c=i*a[i];
            int el=a[i];
            int nu=0;
            while(i<n && a[i]==el)
            {
                i++;
            }
            c+=(n-i)*el;
            mini=min(mini,c);
        }
        cout<<mini<<"\n";
    }
}