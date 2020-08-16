'''
@Copyright: 《python基础训练》
@File name: ex1.py
@Description: 数字组合
@Author: yangjam
@Version: 
@Date: 2020-06-11 14:19:30
@History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
@LastEditTime: 2020-06-11 14:26:03
'''
# total = 0
# for i in range(1, 5):
#     for j in range(1, 5):
#         for k in range(1, 5):
#             if (i != j) and (j != k) and (i != k):
#                 print(i, j, k)
#                 total += 1
# print(total)
import itertools
sum = 0
a = [1, 2, 3, 4]
for i in itertools.permutations(a, 3):
    print(i)
    sum += 1
print(sum)