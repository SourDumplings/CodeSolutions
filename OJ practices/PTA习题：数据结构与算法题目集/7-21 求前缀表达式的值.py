#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-03-13 17:35:46
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://pintia.cn/problem-sets/15/problems/836
注意考虑单数字的情况和除以零的情况
'''


def main():
    elements = input().split(' ')
    num = []
    for e in elements[::-1]:
        try:
            n = float(e)
            num.append(n)
        except ValueError:
            n1 = num.pop()
            n2 = num.pop()
            if e == '/':
                try:
                    res = n1 / n2
                except ZeroDivisionError:
                    print("ERROR")
                    return
            elif e == '*':
                res = n1 * n2
            elif e == '+':
                res = n1 + n2
            elif e == '-':
                res = n1 - n2
            num.append(res)
    print("%.1f" % num[0])
    return


if __name__ == '__main__':
    main()
    # code
