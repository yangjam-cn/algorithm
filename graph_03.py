'''
@Author: youngjam
@Date: 2020-04-22 11:43:57
@LastEditTime: 2020-04-22 13:16:52
@Description: 图的邻接表表示法《图解数据结构使用python》
@logs: 
'''
class list_node:
    def __init__(self):
        self.data = 0
        self.next = None

# 创建图节点数组
head = [list_node] * 6
new_node = list_node()

data = [[1, 2], [2, 1], [2, 5], [5, 2],\
    [2, 3], [3, 2], [2, 4], [4, 2],\
    [3, 4], [4, 3], [3, 5], [5, 3],\
    [4, 5], [5, 4]]

print("The adjacency list contents of the graph")
print("========================")
for i in range(1, 6):
    head[i].val = i
    head[i].next = None
    print('The vertices %d =>' % i, end=' ')
    ptr = head[i]
    for j in range(14):
        if data[j][0] == i:
            new_node.val = data[j][1]
            new_node.next = None
            while ptr != None:
                ptr = ptr.next
            ptr = new_node
            print('[%d]' % new_node.val, end = ' ')
    print()
