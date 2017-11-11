# 字符串中各种字符的个数
# Coding 酸饺子

print('-------------酸饺子学Python-------------')


def CountAlph(string):  # 英文字母个数
    '英文字母个数'
    count = 0
    for each in string:
        if each.isalpha():
            count += 1
    return count


def CountNum(string):  # 数字个数
    '数字个数'
    count = 0
    for each in string:
        if each.isdigit():
            count += 1
    return count


def CountSpa(string):  # 空格个数
    '空格个数'
    count = 0
    space = ' '
    for each in string:
        if each == space:
            count += 1
    return count


def CountOther(string):  # 其他字符个数
    '其他字符个数'
    count = 0
    space = ' '
    for each in string:
        if (each != space) and (not each.isalnum()):
            count += 1
    return count


def Count(*stringtuple):
    l = len(stringtuple)
    if (l == 1) and (isinstance(stringtuple[0], str)):
        print('字符串中共有：英文字母', CountAlph(stringtuple[0]), '个，数字', CountNum(stringtuple[0]),
              '个，空格', CountSpa(stringtuple[0]), '个，其他字符', CountOther(stringtuple[0]), '个')
    elif l > 1:
        i = 1
        for each in stringtuple:
            if not isinstance(each, str):
                print('第', i, '个字符串输入错误！')
                continue
            print('第', i, '个字符串中共有：英文字母 ', CountAlph(each), ' 个，数字 ', CountNum(each),
                  ' 个，空格 ', CountSpa(each), ' 个，其他字符 ', CountOther(each), ' 个')
            i += 1
    else:
        print('输入错误！')      


Count('djkansdjajk12h89398e2sn jiasnd jsadl[2l3ep i90 32e ', '\
    adasdandnu2893eu2e [][d]d32 j2 u2e ;da;sd')
