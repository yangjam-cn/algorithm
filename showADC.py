'''
@Author: yangjam
@Date: 2020-05-28 19:59:36
@LastEditTime: 2020-05-28 20:24:07
@Environment: win10, gcc 8.1.0 & python 3.7.3
@Description: 演示 ADC 逐次逼近数字量化
'''
import numpy as np 
import matplotlib.pyplot as plt 
dataY = np.linspace(0, 3.3, 1024)
dataX = np.linspace(0, 1024, 1024)
plt.bar(dataX, dataY)
plt.show()