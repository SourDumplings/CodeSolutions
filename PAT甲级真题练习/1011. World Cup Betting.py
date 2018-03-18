#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-11-28 16:43:53
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1011
'''


def main():
    g1 = input()
    g2 = input()
    g3 = input()

    def todigit(g):
        for i in range(3):
            g[i] = float(g[i])

    g1 = g1.split(' ')
    g2 = g2.split(' ')
    g3 = g3.split(' ')
    # print(g1, g2, g3)

    todigit(g1)
    todigit(g2)
    todigit(g3)

    m1 = max(g1)
    m2 = max(g2)
    m3 = max(g3)
    # print(m1, m2, m3)

    i1 = int(g1.index(m1))
    i2 = int(g2.index(m2))
    i3 = int(g3.index(m3))
    # print(i1, i2, i3)

    profit = (float(m1) * float(m2) * float(m3) * 0.65 - 1) * 2
    # print(profit)
    b = ['W', 'T', 'L']

    print("%s %s %s %.2f" % (b[i1], b[i2], b[i3], profit + 0.0001))


if __name__ == '__main__':
    main()
