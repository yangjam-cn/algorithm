<!--
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-19 14:28:08
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-20 13:54:05
--> 
<!-- TOC -->

- [vector常见用法详解](#vector常见用法详解)
  - [vector定义](#vector定义)
  - [vector容器内元素访问](#vector容器内元素访问)
  - [vector常用函数](#vector常用函数)
  - [常见用途](#常见用途)
- [set常见用法](#set常见用法)
  - [set的定义](#set的定义)
  - [set容器内元素的访问](#set容器内元素的访问)
  - [set常用函数](#set常用函数)
  - [常见用途](#常见用途-1)
- [string的常见用法](#string的常见用法)
  - [string定义](#string定义)
  - [string中内容的访问](#string中内容的访问)
  - [string常用函数](#string常用函数)
- [map的常用用法](#map的常用用法)
  - [map的定义](#map的定义)
  - [map容器内元素的访问](#map容器内元素的访问)
  - [map常用函数](#map常用函数)
  - [map常见用途](#map常见用途)
- [queue的常见用法](#queue的常见用法)
  - [queue的定义](#queue的定义)
  - [queue内元素的访问](#queue内元素的访问)
  - [queue常用函数](#queue常用函数)
  - [queue的常见用途](#queue的常见用途)
- [priority_queue](#priority_queue)
  - [priority_queue的定义](#priority_queue的定义)
  - [priority_queue内元素访问](#priority_queue内元素访问)
  - [priority_queue常用函数](#priority_queue常用函数)
  - [priority_queue内元素优先级设置](#priority_queue内元素优先级设置)
- [stack的常见用法](#stack的常见用法)
  - [stack的定义](#stack的定义)
  - [stack内元素的访问](#stack内元素的访问)
  - [stack常用函数](#stack常用函数)
- [pair的常见用法](#pair的常见用法)
  - [pair的定义](#pair的定义)
  - [pair中元素的访问](#pair中元素的访问)
  - [pair的常用函数](#pair的常用函数)
  - [pair的常见用途](#pair的常见用途)
- [algorithm头文件下的常用函数](#algorithm头文件下的常用函数)

<!-- /TOC -->

--------------------------------
# vector常见用法详解
## vector定义
```cpp
vector<typename> name;
```
* 上述定义相当于一维`变长数组`
* typename可以是任何基本类型，也可以是STL标准容器，若typename也是STL容器，定义时需在>>间加空格
```cpp
vector<int> name;
vector<double> name;
vector<node> name;    /* node是结构体类型 */
vector<vector<int> > name;    /* 可理解为二维可变数组 */
vector<typename> Arrayname[arraySize];    /* 定义vector数组，每一数组元素都是一个vector容器，该数组维度已固定 */
```
## vector容器内元素访问
* 通过下标访问
  * 对于一个定义为vector< typename > vi的vector容器来说，直接访问vi[index]即可，下标从0~vi.size()-1
* 通过迭代器访问
  * `迭代器(iterator)`可以理解为一种类似指针的东西，定义为：
    ```cpp
    vector<typename>::iterator it;
    ```
  * 这样it就是vector< typename>::iterator型的变量，可以通过类似指针访问数组的方式访问容器内元素(代码见vector_iterator.cpp)
  * 迭代器支持it++和++it(或自减)操作
  * 只有在vector和string中，才允许使用vi.begin()+3这种迭代器加整数的写法
## vector常用函数
* push_back()，在vector后面添加元素，O(1)
* pop_back()，删除vector的尾元素，O(1)
* size()，获取vector中的元素个数，O(1)，返回unsigned
* clear()，清空vector中的所有元素，O(n)
* insert(it, x)，向vector的任意迭代器it处插入一个元素x，O(n)
* erase()，删除单个元素、删除一个区间的所有元素，O(n)
## 常见用途
* 存储数据，用作变长数组
* 用邻接表存储图

-----------------------
# set常见用法
* set是一个内部自动有序且不含重复元素的容器
## set的定义
```cpp
set<typename> name;
```
* typename可以是基本数据类型或者其它STL标准容器
## set容器内元素的访问
* 只能通过迭代器访问
## set常用函数
* insert()，将x插入set容器中，并自动递增排序和去重，O(logN)
* find()，返回set中对应值的迭代器，O(logN)
* erase()，删除单个元素或一个区间的所有元素
* size()，获取set内元素个数，O(1)
* clear()，清空set内所有元素，O(N)
## 常见用途
* 主要用于自动去重并按升序排列

-------------------------
# string的常见用法
## string定义
```cpp
string str;
string str = "abcd";
```
## string中内容的访问
* 通过下标访问
  * 读入和输出整个字符串，则只能使用cin和cout
  * 使用c_str()将string转为字符数组后可使用printf输出
* 通过迭代器访问
## string常用函数
* operatot+=，可以直接将两个字符串拼接起来
* compare operator(==,!=,<,<=,>,>=)，比较大小，规则为字典序
* length()/size()，返回string的长度
* insert()
  * insert(pos, string)在pos号位置插入字符串string
  * insert(it, it2, it3)，it为原字符串的欲插入位置，it2和it3为待插字符的首尾迭代器，将[it2, it3)插入指定位置
* erase()，删除单个元素、删除一个区间的所有元素
  * str.erase(it)
  * str.erase(first, lase)，first为起始迭代器，last为末尾迭代器下一个位置
  * str.erase(pos, length)，pos为开始删除的起始位置，length为删除字符数
* clear()清空string中的所有数据
* substr(pos, len)返回从pos号位置开始、长度为len的子串
* string::npos是一个常数，值为-1，但由于是unsigned_int类型，也可以认为是该类型的最大值4294967195。可以作为find函数失配时的返回值
* find()
  * str.find(str2)当str2是str的子串时，返回其在str中第一次出现的位置，否则返回string::npos
  * str.find(str2, pos)，从pos号位置开始匹配str2，返回值如上
* replace()
  * str.replace(pos, len, str2)把str从pos号位置开始、长度为len的子串替换为str2
  * str.replace(it1, it2, str2)把str迭代器[it1, it2)范围的字串替换为str2

# map的常用用法
* map将任何基本类型(包括STL容器)映射到任何基本类型(包括STL容器)
## map的定义
```cpp
map<typename1, typename2> mp; 
```
* 如果时字符串到整型的映射，必须使用string而不能使用char数组
```cpp
map<string, int> mp;
map<set<int>, string> mp;
```
## map容器内元素的访问
* 通过下标访问
  ```cpp
  map<char, int> mp;
  mp['c'] = 20;
  mp['c'] = 30;
  printf("%d\n", mp['c']);    /* map中的键是唯一的，输出30 */
  ```
* 通过迭代器访问
  ```cpp
  // map<typename, typename>::iterator it;
  map<char, int> mp;
  mp['m'] = 20;
  mp['a'] = 30;
  mp['p'] = 40;
  for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
  {
      printf("%c %d\n",  it->first, it->second);
  }
  ```
  * it->first是当前映射的键，it->second是当前映射的值
  * map会以键从小到大的顺序自动排序，map内部使用红黑树实现，在建立映射过程中自动实现从小到大排序
## map常用函数
* find(key)
* erase()
  * mp.erase(it)
  * mp.erase(key)
  * mp.erase(first, last)
* size()
* clear()
## map常见用途
* 需要建立字符(串)与整数间的映射
* 判断大整数或者其它类型数据是否存在的题目
* 字符串与字符串的映射
* map的键和值之间的映射是唯一的，若要一个键对应多个值，需要使用multimap

-----------------------------
# queue的常见用法
## queue的定义
```cpp
queue<typename> name;
```
## queue内元素的访问
* queue是一种先进先出的限制性数据结构，只能通过front()来访问队首元素，或通过back()来访问队尾元素
## queue常用函数
* push(x)将x进行入队
* front()/back()分别获得队首和队尾元素
* pop()令队首元素出队
* empty()检测queue是否为空，返回true则空
* size()返回queue中的元素个数
## queue的常见用途
* 实现广度优先搜索
* 使用front和pop函数前，使用empty判断队列是否为空

-------------------------
# priority_queue
* 优先队列，内部使用堆实现。队首元素一定是当前队列中优先级最高的那个
## priority_queue的定义
```cpp
priority_queue<typename> name;
```
## priority_queue内元素访问
* 只能通过top()函数访问
## priority_queue常用函数
* push(x)
* top()
* pop()
* empty()
* size()
## priority_queue内元素优先级设置
* 基本数据类型(int,double,char)等直接使用类型，数字大的优先级
```cpp
priority_queue<int> q;
priority_queue<int, vector<int>, less<int> > q;
/*
 * 两种定义方法等价
 * vector<int>填写的是用来承载底层数据结构堆的容器，<>应与第一个参数一致
 * less<int>是第一个参数的比较类，less表示数字大的优先级高，greater表示数字小的优先级高
 */
```
* 结构体的优先级设置
```cpp
struct fruit
{
  string name;
  int price;
  friend bool operator <(fruit f1, fruit f2)
  {
    return f1.price < f2.price;
  }
};
/*
 * 对"<"进行重载，按水果价格高为高优先级，就可以直接使用fruit类型的优先队列
 * 重载">"会编译错误
 */
/*******************************************/
struct fruit
{
  string name;
  int price;
}f1, f2, f3;
struct cmp
{
  bool operator()(fruit f1, fruit f2)
  {
    return f1.price > f2.price;
  }
};
priority_queue<fruit, vector<fruit>, cmp> q;
```

---------------------------------
# stack的常见用法
## stack的定义
```cpp
stack<typename> name;
```
## stack内元素的访问
* stack只能通过top访问栈顶元素
## stack常用函数
* push(x)将x入栈
* top()获得栈顶元素
* pop()弹出栈顶元素
* empty()检测stack是否为空
* size()返回stack内元素个数

-----------------------------
# pair的常见用法
* pair用来将两个元素绑在一起作为合成元素
## pair的定义
* 头文件<utility>
```cpp
pair<typename1, typename2> name;
pair<string, int> p("haha", 5);
/* 临时构建pair变量 */
p = pair<string, int>("haha", 5);
p = make_pair("haha", 5);
```
## pair中元素的访问
* pair中只有两个元素，分别是first和second，按正常结构体的方式访问
```cpp
pair<string, int> p("haha", 5);
cout << p.first << " " << p.second << endl;
```
## pair的常用函数
* 比较操作数(==,!=,<,<=,>,>=等)，先以first的大小作为标准，当first相等后再判别second的大小
## pair的常见用途
* 用来代替二元结构体及其构造函数
* 作为map的键值对来进行插入
```cpp
map<string, int> mp;
mp.insert(make_pair("haha", 5));
```

---------------------------
# algorithm头文件下的常用函数
* max(x, y),min(x, y),abs(x)
* swap(x, y)
* reverse(it, it2)将数组指针在[it, it2)之间的元素或容器的迭代器在[it, it2)范围内的元素反转
* next_permutation()给出一个序列的全序列的下一个序列
* fill()可以把数组或容器中某一段区间赋为某个相同的值
* sort()
  * 使用sort排序
  ```cpp
  sort(首元素地址(必填), 尾元素地址的下一个地址(必填), 比较函数(非必填));
  /* 若不写比较函数，则默认按升序排列 */
  ```
  * 实现比较函数
    * 基本数据类型
      * 若不写则默认按从小到大排序
      * 若要从大到小排列，则需要自定义比较函数
      ```cpp
      bool cmp(int, int)
      {
        return a > b;
      }
      ```
    * 结构体数组的排序
      ```cpp
      struct node
      {
        int x, y;
      };
      /* 从大到小排序 */
      bool cmp(node a, node b)
      {
        return a.x > b.x;
      }
      /* 从小到大排序 */
      bool cmp(node a, node b)
      {
        if (a.x != b.x)
          return a.x < b.x;
        else
          return a.y < b.y;
      }
    * 容器的排序
      * 只有vector、string、deque可以使用sort
* lower_bound()和upper_bound()在有序数组和容器中
  * lower_bound(first, last, val)寻找在数组或容器的[first, last)范围内第一个大于等于val的元素的位置，数组返回指针，容器返回其迭代器
  * upper_bound(first, last, val)寻找[first, last)范围内第一个值大于val的元素的位置
  * 若没有需要寻找的元素，则返回可以插入该元素的位置的指针或迭代器
