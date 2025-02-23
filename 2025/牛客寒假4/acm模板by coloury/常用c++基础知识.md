```c++
swap(a,b)//互换a与b的值
lower_bound( begin,end,num)//从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。
upper_bound( begin,end,num)//从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。
__builtin_popcount(n)//计算n的二进制位中2的个数
__builtin_ctzll(n);//计算最低有效位1的位置
__builtin_parityll(n);//判断二进制数的奇偶性，奇为1偶为0；
__lg(n);//找到最高位1的二进制;
ranges::sort(capacity, greater());//默认升序排列，加上greater()变为降序排列。
reduce(apple.begin(),apple.end(),0);//初始值是0，计算apple中的总和
accumulate(nums.begin(),nums.end(),0);//如果用不了reduce
sort(nums.begin(), nums.end(), [](auto& a, auto& b) { return a[1] > b[1]; });//根据pair中second排序的方法，如果是二维数组同样适用
iota(f.begin(), f.end(), 0);//从第一值开始赋值，往后每赋一个+1，想当初{0,1,2,3,4,5}
memset(nums,-1,sizeof(nums))//把nums所有位置都设置为-1
ranges::make_heap(h,greater<>());//最小堆，按照降序排列,O(n) 堆化
max_element(nums.begin(),nums.end()) //查找数组中最大的元素；
ceil(n)//向上取证小数;

```

```c++
  const int MOD = 1'000'000'007;//定义除余方法
```

assign的两种用法:

```
vector<int> v{1,2,3,4,5};
	vector<int> v1;
	v1.assign(v.begin()+1,v.end()-1);
  //复制v数组2 - 4的部分到v1,这个属性可以是任意属性

  vector<char> v;
v.assign(5,'C');
//在v内填充5个C
```

stoi函数用法

```cpp
stoi(str)//默认转为10进制数
stoi(str,0,16)//指定16进制数
a = stoi(str, NULL, 0); //base = 0，自动检测数值进制

str = "  -12  35"; 
a = stoi(str, &pos, 16); //会舍弃空白符


str = "  -ab";
a = stoi(str, &pos, 16); //-(11 + 10*16
```

调试函数

```cpp
int a = 10,b = 20;
assert(a > b)//条件不成立程序终止
```
