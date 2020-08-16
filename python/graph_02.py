# 邻接矩阵构建有向图
arr = [[0] * 6 for row in range(6)]
data = [
    [1, 2], [2, 1], [2, 3], [2, 4], [4, 3], [4, 1]
]
for i in range(6):
    tempi = data[i][0]
    tempj = data[i][1]
    arr[tempi][tempj] = 1
print("directed graph matrix:")
for i in range(1, 6):
    for j in range(1, 6):
        print('%d' % arr[i][j], end = '\t')
    print()