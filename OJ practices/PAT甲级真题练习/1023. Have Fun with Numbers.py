#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-12-01 20:52:18
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1023
'''


def main():
    n = input()
    num = int(n)
    num *= 2
    doubled_n = str(num)

    flag = 1
    for d in doubled_n:
        # print("n = %s, d = %s" % (n, d))
        i = n.find(d)
        if i == -1:
            flag = 0
            break
        n = n.replace(d, '', 1)
    if len(n) > 0:
        flag = 0
    # print(n)

    if flag:
        print("Yes")
    else:
        print("No")
    print(doubled_n)


if __name__ == '__main__':
    main()
