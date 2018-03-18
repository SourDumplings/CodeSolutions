#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-03-01 15:57:26
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1120
'''


def calc_id(num):
    num_s = str(num)
    res = 0
    for each_d in num_s:
        res += int(each_d)
    return res


def main():
    input()
    num = input().split(' ')
    s = set()
    for each in num:
        id = calc_id(each)
        s.add(id)
    print(len(s))
    l = list(s)
    l.sort()
    output = 0
    for each_id in l:
        if output != 0:
            print(' ', end='')
        else:
            output += 1
        print(each_id, end='')
    print()
    return


if __name__ == '__main__':
    main()
    # code
