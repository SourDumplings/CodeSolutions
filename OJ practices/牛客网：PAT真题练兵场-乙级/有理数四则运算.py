#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-11-16 10:28:17
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.nowcoder.com/pat/6/problem/4060
'''

import math as m


def main():

    def gcd(a, b):
        r = a % b
        while r:
            a = b
            b = r
            r = a % b
        gcd = b
        return gcd

    def ToInt(n):
        if n - int(n):
            n *= 10
        return n

    s = input()
    s = s.replace(' ', '/')
    a1 = int(s.split('/')[0])
    b1 = int(s.split('/')[1])
    a2 = int(s.split('/')[2])
    b2 = int(s.split('/')[3])
    # print(a1, b1, a2, b2)

    def OutPut(a, b):
        # print("$$a = %.2f, b = %.2f$$" % (a, b))
        if not a:
            print(0, end='')
        else:
            temp_a = a
            temp_b = b
            g = gcd(temp_a, temp_b)
            temp_a /= g
            temp_b /= g
            if a / b < 0:
                print('(', end='')

            k = int(m.fabs(temp_a) // m.fabs(temp_b))
            if a / b < 0:
                k *= -1
            # print("$$k = %d$$" % k)

            if k:
                print(k, end='')
                if temp_a < 0 and temp_b > 0:
                    temp_a *= -1
                if temp_a > 0 and temp_b < 0:
                    temp_b *= -1
                temp_a = temp_a - m.fabs(k) * temp_b
                if temp_a:
                    print(" %d/%d" % (temp_a, temp_b), end='')
            else:
                if temp_a > 0 and temp_b < 0:
                    print("-%d/%d" % (temp_a, -temp_b), end='')
                else:
                    print("%d/%d" % (temp_a, temp_b), end='')

            if a / b < 0:
                print(')', end='')
        return

    # 和
    OutPut(a1, b1)
    print(" + ", end='')
    OutPut(a2, b2)
    print(" = ", end='')
    a = a1 * b2 + a2 * b1
    b = b1 * b2
    OutPut(a, b)
    print()

    # 差
    OutPut(a1, b1)
    print(" - ", end='')
    OutPut(a2, b2)
    print(" = ", end='')
    a = a1 * b2 - a2 * b1
    b = b1 * b2
    OutPut(a, b)
    print()

    # 积
    OutPut(a1, b1)
    print(" * ", end='')
    OutPut(a2, b2)
    print(" = ", end='')
    a = a1 * a2
    b = b1 * b2
    OutPut(a, b)
    print()

    # 商
    OutPut(a1, b1)
    print(" / ", end='')
    OutPut(a2, b2)
    print(" = ", end='')
    if not a2:
        print("Inf")
    else:
        a = ToInt(a1 / a2)
        b = ToInt(b1 / b2)
        # print("$$a = %.2f, b = %.2f$$" % (a, b))
        OutPut(a, b)

    return


if __name__ == '__main__':
    main()
