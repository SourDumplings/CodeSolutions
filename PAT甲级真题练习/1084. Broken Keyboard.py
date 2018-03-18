#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-16 12:23:56
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1084
'''


def main():
    origin = input().upper()
    actual = input().upper()
    broken = ""
    for c in origin:
        if actual.find(c) == -1:
            broken += c
            actual += c
    print(broken)
    return


if __name__ == '__main__':
    main()
    # code
