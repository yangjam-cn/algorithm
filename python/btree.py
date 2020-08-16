# 二叉树的列表形式实现
# 2020.1.9
def Btree_create(btree, data, length):
    for i in range(0, length):
        level = 0
        while btree[level] != 0:
            if data[i] > btree[level]:
                level = level * 2 + 2
            else:
                level = level * 2 + 1
        btree[level] = data[i]
        print(Btree)

length = 9
data = [1, 6, 3, 5, 4, 7, 8, 9, 2]
Btree = [0] * 32
Btree_create(Btree, data, length)
print(Btree)