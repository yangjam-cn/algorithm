'''
@Author: youngjam
@Date: 2020-04-22 20:34:10
@LastEditTime: 2020-04-22 21:06:46
@Description: 运算表达式的转换《图解数据结构使用python》
@logs: 
'''
MAX = 50
infix_q = [' '] * MAX

def compare(stack_o, infix_o):
    infix_priority = [' '] * 9
    stack_priority = [' '] * 8
    index_s = index_i = 0
    infix_priority[0] = 'q'
    infix_priority[1] = ')'
    infix_priority[2] = '+'
    infix_priority[3] = '-'
    infix_priority[4] = '*'
    infix_priority[5] = '/'
    infix_priority[6] = '^'
    infix_priority[7] = ' '
    infix_priority[8] = ')'

    stack_priority[0] = 'q'
    stack_priority[1] = '('
    stack_priority[2] = '+'
    stack_priority[3] = '-'
    stack_priority[4] = '*'
    stack_priority[5] = '/'
    stack_priority[6] = '^'
    stack_priority[7] = ' '

    while stack_priority[index_s] != stack_o:
        index_s += 1
    
    while infix_priority[index_i] != infix_o:
        index_i += 1
    
    if int(index_s / 2) >= int(index_i / 2):
        return 1
    else:
        return 0
    
def infix_to_postfix():
    global MAX
    global infix_q
    rear = 0; top = 0; i = 0
    index = -1
    stack_t = [' '] * MAX

    str_ = str(input('请开始输入中序表达式：'))

    while i < len(str_):
        index += 1
        infix_q[index] = str_[i]
        i += 1
    
    infix_q[index + 1] = 'q'
    print('后序表达式：', end = '')
    stack_t[top] = 'q'

    for flag in range(index + 2):
        if infix_q[flag] == ')':
            while stack_t[top] != '(':
                print('%c' % stack_t[top], end = '')
                top -= 1
            top -= 1
        elif infix_q[flag] == 'q':
            while stack_t[top] != 'q':
                print('%c' %stack_t[top], end = '')
                top -= 1
        elif infix_q[flag] == '(' or infix_q[flag] == '^' or \
            infix_q[flag] == '*' or infix_q[flag] == '/' or \
                infix_q[flag] == '+' or infix_q[flag] == '-':
                while compare(stack_t[top], infix_q[flag]) == 1:
                    print('%c' % stack_t[top], end='')
                    top -= 1
                top += 1
                stack_t[top] = infix_q[flag]
        else:
            print('%c' % infix_q[flag], end = '')

print("========================")
print('中序表达式转成后序表达式')
print('可以使用的的运算符包括：^, *, \, +, -, (, )等')
print("========================")
infix_to_postfix()

