'''
@Author: youngjam
@Date: 2020-04-23 14:12:56
@LastEditTime: 2020-04-23 14:43:20
@Description: 队列的数组实现《图解数据结构使用python实现》
@logs: 
@Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
'''
import sys

MAX = 10    # 声明队列大小

queue = [0] * MAX   # 声明队列
front = rear = -1   # 定义队列游标，rear指向队尾元素，front指向对首元素前一位置

choice = ''     # 程序控制字

while rear < MAX - 1 and choice != 'e':
    choice = input('[j] => join queue;  [l] => leave queue;  [e] => exit the program :\t')

    if choice == 'j':   # 输入元素加入队列
        val = int(input('input value:'))
        rear += 1
        queue[rear] = val
    
    elif choice == 'l':     # 队首元素出队

        if rear > front:    # 队列尚有元素
            front += 1
            print('the value of left: [%d]' % queue[front])
        
        else:   # 队列为空
            print('queue is empty!')
            sys.exit(0)


print('------------------------')
print('output the all value of queue:')

if rear == MAX - 1:
    print('queue is full!')

elif front >= rear:
    print('queue is empty!')

else:

     while rear > front:
         front += 1
         print('the value of left: [%d]' % queue[front])

print('------------------------')