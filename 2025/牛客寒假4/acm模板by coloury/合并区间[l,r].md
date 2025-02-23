```cpp
int n,m;//n表示有几个元素，m表示有几个区间
cin >> n >> m
vector<int> freq(n + 1,0);
for(int i = 0 ;i < m;i++){
    int l,r;
    cin >> l >> r;
    freq[l - 1]++;
    if(r < n)freq[r]--;//n以后的不受影响，区间本来为1 - n，改为0 - (n - 1)
    
}
for(int i = 1;i < n;i++){
    freq[i] += freq[i - 1];
}
```