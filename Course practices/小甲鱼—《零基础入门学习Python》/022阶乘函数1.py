# 阶乘函数1
# Coding 酸饺子

print('-------------酸饺子学Python-------------')


def factorial(n):
    result = n
    for i in range(1, n):
        result *= i
    return result


number = int(input('请输入一个正整数：'))
result = factorial(number)
print('%d 的阶乘是： %d' % (number, result))
