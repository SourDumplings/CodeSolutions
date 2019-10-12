# 递归求最大公约数
# Coding 酸饺子

print('-------------酸饺子学Python-------------')


def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)


x = int(input('请输入x：'))
y = int(input('请输入y：'))
print('%d 和 %d 的最大公约数为 %d' % (x, y, gcd(x, y)))
