'''
@Copyright: 版权说明
@File name: 文件名
@Description: 说明此程序文件的主要功能，与其它模块或函数的接口，输出值、取值范围、含义及参数间的控制、顺序、独立或依赖关系
@Author: yangjam
@Version: 
@Date: 2020-06-11 14:27:19
@History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
@LastEditTime: 2020-06-11 14:35:34
'''
profit = int(input("show me the money:"))
bouns = 0
thresholds = [100000, 100000, 200000, 200000, 400000]
rates = [0.1, 0.075, 0.05, 0.03, 0.015, 0.01]
for i in range(len(thresholds)):
    if profit <= thresholds[i]:
        bouns += profit * rates[i]
        profit = 0
        break
    else:
        bouns += thresholds[i] * rates[i]
        profit -= thresholds[i]
bouns += profit * rates[-1]
print(bouns)