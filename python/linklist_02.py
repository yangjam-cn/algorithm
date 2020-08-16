# 插入链表节点
import sys

class employee:
    def __init__(self):
        self.num = 0
        self.salary = 0
        self.name = ''
        self.next = None

def findnode(head, num):
    ptr = head
    while ptr != None:
        if ptr.num == num:
            return ptr
        ptr = ptr.next
    return ptr

def insertnode(head, ptr, num, salary, name):
    InsertNode = employee()
    if not InsertNode:
        return None
    InsertNode.num = num
    InsertNode.salary = salary
    InsertNode.name = name
    InsertNode.next = None
    if ptr == None:
        InsertNode.next = head
        return InsertNode
    else:
        if ptr.next == None:
            ptr.next = InsertNode
        else:
            InsertNode.next = ptr.next
            ptr.next = InsertNode
    return head

position = 0

    