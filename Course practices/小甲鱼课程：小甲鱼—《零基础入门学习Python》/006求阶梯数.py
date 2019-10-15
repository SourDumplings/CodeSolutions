#求阶梯数
#Coding 酸饺子

print('-------------酸饺子学Python-------------')
n = 1
while 1:
    if (n % 2 == 1) and (n % 3 == 2) and (n % 5 == 4)\
       and (n % 6 == 5) and (n % 7 == 0):
        print('阶梯数为：')
        print(n)
        break
    n += 1
