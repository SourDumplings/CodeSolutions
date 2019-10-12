#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-12-29 15:16:29
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
W1
'''

import math


def main():
    def isPrime(n):
        if n == 2:
            return True
        elif n == 1:
            return False
        else:
            for i in range(2, int(math.sqrt(n)) + 1):
                if n % i == 0:
                    return False
            else:
                return True

    p = 2
    count = 0
    while True:
        if (isPrime(p)):
            m = 2 ** p - 1
            if (isPrime(m)):
                count += 1
                if (count == 6):
                    with open("W1.寻找第6个默尼森数.txt", 'w') as f:
                        f.write(str(m))
                    break
        p += 1

    return


if __name__ == '__main__':
    main()
