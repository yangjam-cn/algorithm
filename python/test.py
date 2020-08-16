class linked_list:
    def __init__(self):
        self.data = 0
        self.next = None

head = linked_list()
head.data = 1
head.next = None
node = head
node.next = linked_list()
print(node.next)
print(head.next)
# 结果相同,表明node是head的引用,而不是新产生的变量