#2020年 04月 16日 星期四 20:25:15 CST
# 基于链表的的栈python实现

# 定义栈结构
class Node:
    def __init__(self):
        self.data = 0
        self.next = None

top = None

def isEmpty():
    global top
    if (top == None):
        return True
    else:
        return False

def push(data):
    global top
    new_add_node = Node()
    new_add_node.data = data
    new_add_node.next = top
    top = new_add_node

def pop():
    global top
    if isEmpty():
        print("this stack is empty!")
    else:
        ptr = top
        top = top.next
        temp = ptr.data
        return temp
        
while True:
    i = int(input('push = 1; pop = 0; exit = -1:\t'))
    if i == -1:
        break
    elif i == 1:
        value = int(input('input the data: '))
        push(value)
    elif i == 0:
        print('the top element is: %d' % pop())

print('++++++++++++++++')
while(not isEmpty()):
    print('the top element is : %d' % pop())
print('++++++++++++++++')