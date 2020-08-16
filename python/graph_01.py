arr = [[0] * 6 for row in range(6)]
data = [
    [1, 2], [2, 1], [1, 5], [5, 1], [2, 3], [3, 2], [2, 4], [4, 2], [3, 4], [4, 3]
]
for i in range(10):
    # for j in range(2):
        # for k in range(6):
            tempi = data[i][0]
            tempj = data[i][1]
            arr[tempi][tempj] = 1
print('undirected graph matrix:')
for i in range(1, 6):
    for j in range(1, 6):
        print('%d' %arr[i][j], end = '\t')
    print()