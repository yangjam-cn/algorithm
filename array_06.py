# 矩阵转置
arrA = [
    [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]
]
N = 4
arrB = [[None] * N for row in range(N)]
print('original matrix content:')
for i in range(N):
    for j in range(N):
        print('%d' % arrA[i][j], end = '\t')
    print()
for i in range(N):
    for j in range(N):
        arrB[i][j] = arrA[j][i]
print('the contents of the transpose:')
for i in range(N):
    for j in range(N):
        print('%d' % arrB[i][j], end = '\t')
    print()
