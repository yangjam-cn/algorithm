'''
@Author: yangjam
@Date: 2020-05-26 15:09:54
@LastEditTime: 2020-05-26 19:47:18
@Environment: win10, gcc 8.1.0 & python 3.7.3
@Description: python基础知识回顾
'''
'''内建原子数据类型'''
# 整数、浮点、布尔
# print(25536/256)
# print(25536%256)
# print(hex(25536))
# print(hex(int(25536/256)))
# print(hex(25536%256))
# print(True and False)
# print(True or False)
# print(not True)
'''内建集合数据类型'''
# list
# mylist = [1, 2, 3, True, False, 3.12, "hello"]
# # 运算符
# print(mylist[3])    ##索引，取序列中的某一个元素 []
# print(mylist + ["python"])      ##连接，将序列连接在一起 +
# print(['a'] * 5)    ##重复N次连接 *
# print(3 in mylist)      ##成员，询问序列中是否有某元素 in
# print(len(mylist))      ##长度，询问序列的元素个数  len
# print(mylist[2:5])      ##切片，取出序列一部分
# 字符串
# mystring = "hello python"
# 元组，与列表相似，但是和字符串一样不可修改
# myTuple = (2, True, 3.21)
# 集，不可修改的无序集合，不允许重复元素
# mySet = {1.2, "Hello", 5, True}
# # 运算符
# print(3.12 in mySet)    ##询问集中是否有某个元素
# print(len(mySet))       ##获取集中元素的个数
# testSet = {"test", "Set", "Hello"}
# print(mySet | testSet)  ##返回两个集合的共集
# print(mySet & testSet)  ##返回两个集合的并集
# print(mySet - testSet)  ##返回mySet关于testSet的补集
# print(mySet <= testSet) ##询问mySet中所有的元素是否在testSet中
# 字典
# myDic = {"yellow":1, "whilte":2, "black": 3}
# # 运算符
# print(myDic["yellow"])  ##返回相关联的值
# print("yellow" in myDic)    ##查询是否在字典中
# del myDic['yellow']     ##删除键值对
'''定义新类'''
'''
class Fraction:
    # 构造方法用于创建类
    def __init__(self, top, bottom):
        self.num = top
        self.den = bottom
    

    # 重写默认实现方法
    # 转化为字符串
    def __str__(self):
        return str(self.num) + '/' + str(self.den)
    # 相加
    def __add__(self, otherfraction):
        newNum = self.num * otherfraction.den + self.den * otherfraction.num
        newDen = self.den * otherfraction.den
        return Fraction(newNum, newDen).simple()
    # 深相等
    def __eq__(self, otherfraction):
        firstNum = self.num * otherfraction.den
        secondNum = self.den * otherfraction.num
        return firstNum == secondNum

    def simple(self):
        num = self.num
        den = self.den
        while self.num % self.den != 0:
            oldNum = self.num
            oldDen = self.den
            self.num = oldDen
            self.den = oldNum % oldDen
        self.num = num // self.den
        self.den = den // self.den
        return self

f1 = Fraction(1, 4)
print(f1)
f2 = Fraction(1, 2)
f3 = f1 + f2
print(f3)
print(f1 == Fraction(1, 4))
'''
