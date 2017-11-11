# 判断回文联
# Coding 酸饺子

print('-------------酸饺子学Python-------------')


def Judg(sentence):
    length = len(sentence)
    for i in range(0, length):
        if sentence[i] != sentence[length - i - 1]:
            print('这不是回文联！')
            break
    if i == length - 1:
        print('这是回文联！')


sentence = input('请输入一句话：')
Judg(sentence)
