# 矩阵相乘
def MatrixMultiply(arrA, arrB, arrC, M, N, P):
    global C
    if M <= 0 or N <= 0 or P <= 0:
        print("error: dimsion M, N, P must grater than 0")
        return
    for i in range(M):
        for j in range(P):
            Temp = 0
            for k in range(N):
                Temp = Temp + int(arrA[i*N+k]) * int(arrB[k*P+j])
            arrC[i*P+j] = Temp


print('please input the dimsion of matrix A(M, N):')
M = int(input('M = '))
N = int(input('N = '))
A = [None] * M * N

print('please input the element of matrix A:')
for i in range(M):
    for j in range(N):
        A[i*N+j] = input('a%d%d = ' % (i, j))

print('please input the dimsion of matrix B(N, P):')
N = int(input('N = '))
P = int(input('P = '))
B = [None] * N * P 

print('please input the element of matrix B:')
for i in range(N):
    for j in range(P):
        B[i*P+j] = input('b%d%d = ' % (i, j))

C = [None] * M * P 
MatrixMultiply(A, B, C, M, N, P)
print('A * B =')
for i in range(M):
    for j in range(P):
        print("%d" % C[i*P+j], end = '\t')
    print()