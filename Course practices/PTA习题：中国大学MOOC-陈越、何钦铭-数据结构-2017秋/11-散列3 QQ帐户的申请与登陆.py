#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-11-17 19:12:51
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://pintia.cn/problem-sets/900290821590183936/problems/928950160066985984
'''


def main():
    N = int(input())
    data = {}

    for i in range(N):
        sentence = input()
        order = sentence.split(' ')[0]
        num = sentence.split(' ')[1]
        p = sentence.split(' ')[2]

        if order == 'N':
            if data.get(num):
                print("ERROR: Exist")
            else:
                data[num] = p
                print("New: OK")
        elif order == 'L':
            if not data.get(num):
                print("ERROR: Not Exist")
            elif p != data.get(num):
                print("ERROR: Wrong PW")
            else:
                print("Login: OK")


if __name__ == '__main__':
    main()
