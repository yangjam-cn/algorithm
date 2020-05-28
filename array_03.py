num = [
    [
        [33, 45, 67], [23, 71, 66], [55, 38, 66]
    ],
    [
        [21, 9, 15], [38, 69, 18], [90, 101, 89]
    ]
]
value = num[0][0][0]
for i in range(2):
    for j in range(3):
        for k in range(3):
            if (value >= num[i][j][k]):
                value = num[i][j][k]
print('least value: %d' %value)
print(num)