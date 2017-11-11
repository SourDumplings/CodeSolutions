# 大量字母解密
# Coding 酸饺子

print('-------------酸饺子学Python-------------')


def Decode(string):
    l = len(string)
    code = ''

    def Key(i):  # 判断该字母是否是一位密码
        if (i < 3) or (i > l - 4):
            return 0
        elif (string[i - 3].isupper()) and (string[i - 2].isupper())\
                and (string[i - 1].isupper()) and (string[i + 1].isupper())\
                and (string[i + 2].isupper()) and (string[i + 3].isupper())\
                and (not(string[i - 4].isupper())) and (not(string[i + 4].isupper())):
            return 1

    for i in range(l):
        if string[i].islower():
            if Key(i):
                code += string[i]

    print('密码是：', code)

string = '''需要解密的字符串'''
Decode(string)
