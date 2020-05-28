# 遍历单向链表
import os

class student:
    def __init__(self):
        self.name = ''
        self.Math = 0
        self.English = 0
        self.no = ''
        self.next = None

head = student()
head.next = None
ptr = head
Math_sum = English_sum = num = student_no = 0
select = 0

while select != 2:
    print('(1) add  (2)leave =>')
    try:
        select = int(input('please input your select:'))
    except ValueError:
        print("input error!")
        print('input again:')
    if select == 1:
        new_data = student()
        new_data.name = input('name:')
        new_data.no = input('student id:')
        new_data.Math = eval(input('math grade:'))
        new_data.English = eval(input('English grade:'))
        new_data.next = None
        ptr.next = new_data
        ptr = ptr.next
        num += 1

ptr = head.next
print()
while ptr != None:
    print("name: %s\tstudent ID: %s\tmath grade: %d\tEnglish grade: %d"\
        %(ptr.name, ptr.no, ptr.Math, ptr.English))
    Math_sum += ptr.Math
    English_sum += ptr.English
    student_no += 1
    ptr = ptr.next

if student_no != 0:
    print('==============================================')
    print('average grade: math = %.2f\tenglish = %.2f' % (Math_sum/student_no, English_sum/student_no))
