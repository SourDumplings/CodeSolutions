#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-12-05 20:30:26
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1035
'''


def main():
    N = int(input())

    modified = []
    flag = 0

    for i in range(N):
        account = input().split()
        pw0 = account[1]
        pw = pw0
        pw = pw.replace('1', '@')
        pw = pw.replace('0', '%')
        pw = pw.replace('O', 'o')
        pw = pw.replace('l', 'L')
        if pw != pw0:
            modified.append([account[0], pw])
            flag += 1

    if (flag):
        print(flag)
        for each_modified in modified:
            print(each_modified[0], each_modified[1])
    elif N > 1:
        print("There are %d accounts and no account is modified" % N)
    else:
        print("There is 1 account and no account is modified")


if __name__ == '__main__':
    main()
