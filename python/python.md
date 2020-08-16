<!--
 * @Copyright: 《python算法教程》
 * @File name: python.md
 * @Description: 
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-09 16:51:47
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-12 22:03:56
--> 
# python算法
## 计数初步
### 求和式
* 数学符号与求和  
  x\*sum(S) == sum(x\*y for y in S) ==> $x\sum_{y \in S}y=\sum_{y \in S}xy$  
  $\sum_{i=m}^{n}f(i)==>sum(f(i)\ for\ i\ in\ range(m,\ n+1))$
* 两种求和  
$\sum_{i=0}^{n-1}i=\frac{n(n-1)}{2}$  
$\sum_{i=0}^{\log_2{n}-1}2^i=n-1\ ==>\ \sum_{i=0}^{n}2^i=2^{n+1}-1$
### 二项式系数  
$\binom{n}{k}=\frac{n!}{k!(n-k)!}$
### 递归  
$T(n)=a\cdot T(g(n))+f(n)\quad a指递归调用数量，g(n)是递归过程子问题的规模，f(n)代表函数中的额外操作$  
|递归式|解决方案|应用实例|
|--------|:--------:|:--------|
|$T(n)=T(n-1)+1$|$\Theta(n)$|序列化处理问题，如归简操作|
|$T(n)=T(n-1)+n$|$\Theta(n^2)$|握手问题|
|$T(n)=2T(n-1)+1$|$\Theta(2^n)$|汉诺塔问题|
|$T(n)=2T(n-1)+n$|$\Theta(2^n)$| |
|$T(n)=T(n/2)+1$|$\Theta(\lg{n})$|二分搜索|
|$T(n)=T(n/2)+n$|$\Theta(n)$|随机选择问题、平均情况问题|
|$T(n)=2T(n/2)+1$|$\Theta(n)$|树的遍历问题|
|$T(n)=2T(n/2)+n$|$\Theta(n\lg{n})$|分治法排序|
### 主定理
  $T(n)=aT(n/b)+f(n)$
  主要思想是：假设存在a重递归调用，每重递归调用处理掉一定比例的数据(数据集的1/b)。除了这些递归调用外，算法还有一个额外的f(n)操作单元。
  |前提条件|解决方案|相关示例|
  |:-----|:-----|:-----|
  |$f(n)\in O(n^{\log_b{a}-\varepsilon})$|$T(n)\in \Theta(n^{\log_b{a}})$|$T(n)=2T(n/2)+\lg{n}$|
  |$f(n)\in \Theta(n^{\log_b{a}})$|$T(n)\in \Theta(n^{\log_b{a}}\lg{n})$|$T(n)=2T(n/4)+\sqrt{n}$|
  |$f(n)\in \Omega(n^{\log_b{a}+\varepsilon})$|$T(n)\in \Theta(f(n))$|$T(n)=2T(n/3)+n$|
## 归纳、递归及归简
