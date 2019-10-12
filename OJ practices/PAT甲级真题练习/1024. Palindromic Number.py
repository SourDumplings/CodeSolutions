#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-12-02 12:14:01
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1024
'''


def main():
    temp = input()
    temp = temp.split(' ')
    N = int(temp[0])
    K = int(temp[1])

    def judge(n):
        n = str(n)
        l = len(n)
        flag = 1
        for i in range(l):
            if n[i] != n[l - i - 1]:
                flag = 0
                break
        return flag

    n = N
    flag = 0
    for i in range(K):
        if judge(n):
            print(n)
            print(i)
            flag = 1
            break
        n = str(n)
        n_r = n[::-1]
        n = int(n) + int(n_r)
        # print(n, ' ', i)

    if not flag:
        print(n)
        print(K)


if __name__ == '__main__':
    main()
