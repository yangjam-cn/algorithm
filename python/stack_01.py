# 2020年 04月 16日 星期四 14:57:00 CST
# 栈的python实现，基于列表
MAXSTACK = 100
global stack
stack = [None] * MAXSTACK
top = -1

def isEmpty():
    if top == -1:
        return True
    else:
        return False

def push(data):
    global top
    global MAXSTACK
    global stack
    if top >= MAXSTACK:
        print("堆栈已满，无法加入")
    else:
        top += 1
        stack[top] = data

def pop():
    global top
    global stack
    if isEmpty():
        print("堆栈是空的")
    else:
        print("弹出的元素是：%d" % stack[top])
        top -= 1

i = 2
count = 0
while True:
    i = int(input("要压入堆栈，请输1；要弹出请输0；结束输入-1"))
    if i == -1:
        break
    elif i == 1:
        val = int(input('请输入元素值：'))
        push(val)
    elif i == 0:
        pop()

print("============")
if top < 0:
    print("堆栈已空")
else:
    i = top
    while i >= 0:
        print("堆栈弹出顺序为：%d" % stack[i])
        count += 1
        i -= 1
print("============")

 