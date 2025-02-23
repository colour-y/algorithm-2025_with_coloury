有三个数 : n,m,k(产出m需要n个单位,每个单位仅能使用一次,达到预期值k需要多少个初始单位)
```cpp
ll l = n,r = k;
for(;md = l + r >> 1;l < r){
    if(md + (md - n) / (md - m) * m + m >= k) r = md;
    else l = md + 1;
    ans = min(ans,l);
}
```