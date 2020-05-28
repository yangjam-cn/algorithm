N = 2
arr = [[None] * N for row in range(N)]
print('|a1 b1|')
print('|a2 b2|')
arr[0][0] = input('please input a1:')
arr[0][1] = input('please input b1:')
arr[1][0] = input('please input a2:')
arr[1][1] = input('please input b2:')
result = int(arr[0][0]) * int(arr[1][1]) - int(arr[0][1]) * int(arr[1][0])
print('|%d %d|' % (int(arr[0][0]), int(arr[0][1])))
print('|%d %d|' % (int(arr[1][0]), int(arr[1][1])))
print('det = %d' % result)