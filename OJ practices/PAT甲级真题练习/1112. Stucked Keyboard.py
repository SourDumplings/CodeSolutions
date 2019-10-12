#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-28 09:43:31
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1112
'''


def main():
    # code
    k = int(input())
    origin = input()
    temp = origin
    charSet = []
    res = origin
    stuck = ""
    for eachC in temp:
        charSet.append(eachC)
        temp = temp.replace(eachC, "")
    for eachC in charSet:
        target = eachC * k
        if target in origin:
            origin = origin.replace(target, "")
            if eachC not in origin:
                stuck += eachC
                res = res.replace(target, eachC)
    print(stuck)
    print(res)

    return


if __name__ == '__main__':
    main()
    # code
