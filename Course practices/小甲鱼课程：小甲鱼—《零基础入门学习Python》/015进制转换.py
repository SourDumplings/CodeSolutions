# 进制转换
# Coding 酸饺子

print('-------------酸饺子学Python-------------')
temp = 0

while True:
    temp = input('请输入一个十进制整数（输入Q结束程序）：')
    if temp == 'Q':
        break
    elif temp.isdigit():
        num = int(temp)
        if isinstance(num, int):
            num16 = '%#x' % num
            num8 = '%#o' % num
            num2 = bin(num)

            print('''十进制→十六进制：{0}
十进制→八进制：{1}
十进制→二进制：{2}'''.format(num16, num8, num2))
        else:
            print('输入错误！')
    else:
        print('输入错误！')
