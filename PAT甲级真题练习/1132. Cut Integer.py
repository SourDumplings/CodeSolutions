#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-03-06 17:07:10
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1132
注意任何时候除法或者是取余运算都要考虑到有可能除以0
'''


def main():
    N = int(input())
    for i in range(N):
        num = str(int(input()))
        l = len(num)
        num1 = num[:int(l / 2)]
        num2 = num[int(l / 2):]
        try:
            if int(num) % (int(num1) * int(num2)) == 0:
                print("Yes")
            else:
                print("No")
        except:
            print("No")
    return


if __name__ == '__main__':
    main()
    # code
