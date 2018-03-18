#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-12-03 13:42:33
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1032
'''


def main():
    l1 = {}
    l = {}
    s = input().split(' ')
    start1 = int(s[0])
    start2 = int(s[1])
    N = int(s[2])

    for i in range(N):
        s = input().split(' ')
        this = int(s[0])
        next_node = int(s[2])
        l[this] = next_node

    while True:
        if start1 == -1:
            break
        l1[start1] = l[start1]
        start1 = l1[start1]

    while True:
        if start2 == -1:
            common = -1
            break
        if l1.get(start2) is not None:
            common = start2
            break
        start2 = l[start2]

    if common != -1:
        print("%05d" % common)
    else:
        print(-1)

    return


if __name__ == '__main__':
    main()
