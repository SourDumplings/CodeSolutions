#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-26 11:02:18
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1108
'''


def main():
    input()
    data = input().split(' ')
    count = 0
    sum_res = 0
    for each in data:
        try:
            num = float(each)
            if num < -1000 or num > 1000 or num * 100 - int(num * 100) > 0:
                raise ValueError
            count += 1
            sum_res += num
        except ValueError:
            print("ERROR: %s is not a legal number" % each)
    if count != 0:
        if count == 1:
            print("The average of 1 number is %.2f" % sum_res)
        else:
            print("The average of %d numbers is %.2f" %
                  (count, sum_res / count))
    else:
        print("The average of 0 numbers is Undefined")
    return


if __name__ == '__main__':
    main()
    # code
