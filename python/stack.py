# 2020.1.6
# 基于数组的堆栈实现

# ********** example ********** #
Max_Stack = 100
global stack
stack = [None] * Max_Stack
top = -1

def is_empty():
    if top ==  -1:
        return True
    else:
        return False
def push(data):
    global top
    global Max_Stack
    global stack
    if top >= Max_Stack - 1:
        print("stack is full!")
    else:
        top += 1
        stack[top] = data

def pop():
    global top
    global stack
    if is_empty():
        print("stack is empty!");
    else:
        print("element is:%d" % stack[top])
        top -= 1

i = 2
count = 0
while True:
    i = int(input("push : 1; pop : 0; stop : -1==>"))
    if i == -1:
        break
    elif i == 1:
        value = int(input('input element'))
        push(value)
    elif i == 0:
        pop()
print('=======================')
if top < 0:
    print('\nstack is empty!')
else:
    i = top
    while i >= 0:
        print('pop :%d' % (stack[i]))
        count += 1
        i -= 1
print('=======================')

