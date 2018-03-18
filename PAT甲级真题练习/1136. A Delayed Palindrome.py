#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-03-07 13:50:54
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1136
'''


def is_palindromic(N):
    l = len(N)
    for i in range(l):
        if N[i] != N[l - i - 1]:
            return False
    return True


def main():
    N = input()
    p = False
    for i in range(10):
        if (is_palindromic(N)):
            print("%d is a palindromic number." % int(N))
            p = True
            break
        else:
            temp = list(str(int(N)))
            temp.reverse()
            Nr = ""
            for each_d in temp:
                Nr += each_d
            Sum = int(N) + int(Nr)
            print("%d + %d = %d" % (int(N), int(Nr), Sum))
            N = str(Sum)
    if not p:
        print("Not found in 10 iterations.")
    return


if __name__ == '__main__':
    main()
    # code
