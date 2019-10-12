#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-11-23 20:49:48
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.nowcoder.com/pat/6/problem/4065
'''


def main():
    offer = input()
    offer = list(offer)
    want = input()
    shortnum = 0
    redundant_num = 0
    for each_want in want:
        try:
            offer.remove(each_want)
        except ValueError as v:
            shortnum += 1
        else:
            redundant_num = len(offer)

    if shortnum:
        print("No %d" % shortnum)
    else:
        print("Yes %d" % redundant_num)


if __name__ == '__main__':
    main()
