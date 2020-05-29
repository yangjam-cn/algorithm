'''
@Author: yangjam
@Date: 2020-05-28 19:59:36
@LastEditTime: 2020-05-28 21:29:27
@Environment: win10, gcc 8.1.0 & python 3.7.3
@Description: 演示 ADC 逐次逼近数字量化
'''
import numpy as np 
import matplotlib.pyplot as plt 
bits = 12
Vref = 2.4
dataY = np.linspace(0, Vref, 2**bits)
dataX = np.linspace(0, 2**bits, 2**bits)
plt.bar(dataX, dataY)
plt.show()