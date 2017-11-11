#打印每个人成绩
#Coding 酸饺子

print('-------------酸饺子学Python-------------')
member = ['小甲鱼', 88, '黑夜', 90, '迷途', 85, '怡静', 90, '秋舞斜阳', 88]
l = len(member)

for i in range(l):
    if i%2 == 0:
        print(member[i], member[i+1])
