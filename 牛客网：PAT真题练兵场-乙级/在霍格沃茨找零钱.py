#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-11-23 18:39:59
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.nowcoder.com/pat/6/problem/4063
'''


def main():
    temp = input()
    y = temp.split(' ')[0]
    # print(y)
    s = temp.split(' ')[1]
    # print(s)
    y = y.split('.')
    s = s.split('.')
    y_k = int(y[2]) + int(y[1]) * 29 + int(y[0]) * 17 * 29
    # print(y_k)
    s_k = int(s[2]) + int(s[1]) * 29 + int(s[0]) * 17 * 29
    # print(s_k)
    charge = s_k - y_k
    # print(charge)
    if charge < 0:
        charge *= -1
        print('-', end='')
    charge_g = charge // (29 * 17)
    charge_s = (charge % (29 * 17)) // 29
    charge_k = charge % 29
    print("%d.%d.%d" % (charge_g, charge_s, charge_k))


if __name__ == '__main__':
    main()
