#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-06 10:35:42
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1065
'''


def main():
    n = int(input())
    for i in range(n):
        temp = input().split(' ')
        A = int(temp[0])
        B = int(temp[1])
        C = int(temp[2])
        print("Case #%d: " % (i + 1), end='')
        if A + B > C:
            print("true")
        else:
            print("false")
    return


if __name__ == '__main__':
    main()
    # code
