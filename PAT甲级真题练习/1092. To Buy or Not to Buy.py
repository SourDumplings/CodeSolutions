#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-18 17:52:59
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1092
'''


def make_dict(s):
    tempSet = set(s)
    res = {}
    for c in tempSet:
        res[c] = s.count(c)
    return res


def main():
    tempSell = input()
    sell = make_dict(tempSell)
    tempBuy = input()
    buy = make_dict(tempBuy)
    judge = True
    for c, num in buy.items():
        if sell.get(c) is None or sell.get(c) < num:
            judge = False
            break
    if judge:
        extra = len(tempSell) - len(tempBuy)
        print("Yes %d" % extra)
    else:
        missing = 0
        for c, num in buy.items():
            if sell.get(c) is None:
                missing += num
            elif sell.get(c) < num:
                missing += num - sell.get(c)
        print("No %d" % missing)
    return


if __name__ == '__main__':
    main()
    # code
