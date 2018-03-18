#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-21 18:08:33
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1100
'''

g = ["tret", "jan", "feb", "mar", "apr", "may",
     "jun", "jly", "aug", "sep", "oct", "nov", "dec", "tam"]
s = ["", "tam", "hel", "maa", "huh", "tou", "kes",
     "hei", "elo", "syy", "lok", "mer", "jou"]


def to_mars(e):
    if e == 0:
        print("tret")
        return
    gDigit = e % 13
    sDigit = e // 13
    if sDigit:
        print(s[sDigit], end='')
        if gDigit != 0:
            print(' ', end='')
        else:
            print()
    if gDigit != 0:
        print(g[gDigit])
    return


def to_earth(m):
    m = m.split(' ')
    if (len(m) == 1):
        try:
            print(g.index(m[0]))
        except ValueError:
            print(s.index(m[0]) * 13)
    else:
        e = s.index(m[0]) * 13 + g.index(m[1])
        print(e)
    return


def main():
    N = int(input())
    for i in range(N):
        l = input()
        if l[0].isdigit():
            to_mars(int(l))
        else:
            to_earth(l)
    return


if __name__ == '__main__':
    main()
    # code
