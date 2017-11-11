print('------------酸饺子学Python------------')
#判断一个年份是否是闰年
#Coding 酸饺子

temp = input('输入一个年份吧：\n')
while not temp.isdigit():
    print('这个不是年份吧……')
year = int(temp)
if year/400 == int(year/400):
    print('闰年！')
else:
    if (year/4 == int(year/4)) and (year/100 != int(year/100)):
        print('闰年！')
    else:
        print('平年！')
    
