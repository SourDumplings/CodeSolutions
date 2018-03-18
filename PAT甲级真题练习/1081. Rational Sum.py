#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-15 18:25:00
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1081
'''


def get_gcd(a, b):
    while b:
        r = a % b
        a = b
        b = r
    return a


def simplify(nu, de):
    gcd = get_gcd(nu, de)
    return nu / gcd, de / gcd


def calc_sum(num_list):
    nu1 = int(num_list[0].split('/')[0])
    de1 = int(num_list[0].split('/')[1])
    if len(num_list) == 2:
        nu2 = int(num_list[1].split('/')[0])
        de2 = int(num_list[1].split('/')[1])
    else:
        nu2, de2 = calc_sum(num_list[1:])
    nu, de = simplify(nu1 * de2 + nu2 * de1, de1 * de2)
    return nu, de


def main():
    N = input()
    num = input().split(' ')
    nu, de = calc_sum(num)
    if nu * de < 0:
        nu = abs(nu)
        de = abs(de)
        print('-', end='')
    if nu == 0:
        print(0)
    elif nu > de:
        i = nu // de
        nu -= i * de
        print(int(i), end='')
        if nu != 0:
            print(end=' ')
        else:
            print()
    if nu != 0:
        print(int(nu), end='')
        if de != 1:
            print("/%d" % de)
        else:
            print()
    return


if __name__ == '__main__':
    main()
    # code
