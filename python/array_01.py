Score = [87, 66, 90, 65, 70]
Total_Score = 0
for count in range(5):
    print('第 %d 位同学的分数: %d' %(count + 1, Score[count]))
    Total_Score += Score[count]
print('----------------------------------')
print('5位同学的总分数: %d' %Total_Score)