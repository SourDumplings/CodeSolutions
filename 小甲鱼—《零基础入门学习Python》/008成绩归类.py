# 成绩归类
# Coding 酸饺子

print('-------------酸饺子学Python-------------')
temp = input('请输入成绩：')
grade = int(temp)
if 60 <= grade < 80:
    print('C')
elif 80 <= grade < 90:
    print('B')
elif 90 <= grade <= 100:
    print('A')
elif 0 <= grade < 60:
    print('D')
else:
    print('输入错误！')
