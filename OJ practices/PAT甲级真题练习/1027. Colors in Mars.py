#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-12-01 21:26:33
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1027
'''


def main():
    n = input()
    n = n.split(' ')
    r = int(n[0])
    g = int(n[1])
    b = int(n[2])

    def ProssEveryBit(d):
        if d < 10:
            result = str(d)
        elif d == 10:
            result = 'A'
        elif d == 11:
            result = 'B'
        else:
            result = 'C'
        return result

    def GetMarNum(n):
        s = ''
        d1 = n // 13
        s += ProssEveryBit(d1)
        d2 = n % 13
        s += ProssEveryBit(d2)
        return s

    def ChangeFormat(s):
        if len(s) == 1:
            s = '0' + s[0]
        return s

    r = GetMarNum(r)
    g = GetMarNum(g)
    b = GetMarNum(b)

    r = ChangeFormat(r)
    g = ChangeFormat(g)
    b = ChangeFormat(b)

    print("#%s%s%s" % (r, g, b))


if __name__ == '__main__':
    main()
