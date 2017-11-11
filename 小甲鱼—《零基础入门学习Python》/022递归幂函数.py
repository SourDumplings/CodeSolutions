# 递归幂函数
# Coding 酸饺子

print('-------------酸饺子学Python-------------')


def power(x, y):
    if y == 0:
        return 1
    else:
        return x * power(x, y - 1)


x = float(input('请输入底数：'))
y = float(input('请输入指数：'))
result = power(x, y)
print('结果为：%f' % result)
