#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-03-08 10:24:58
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1001
'''


def main():
    temp = input().split(' ')
    a = int(temp[0])
    b = int(temp[1])
    s = str(a + b)
    res = ""
    count = 0
    r = reversed(s)
    for i in r:
        res += i
        count += 1
        if count % 3 == 0:
            res += ','
    if res[-1] == ',':
        res = res[:-1]
    if res[-1] == '-' and res[-2] == ',':
        res = res[:-2] + '-'
    res = reversed(res)
    for d in res:
        print(d, end='')
    print()
    return


if __name__ == '__main__':
    main()
    # code
