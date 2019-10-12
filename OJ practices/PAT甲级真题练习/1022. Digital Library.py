#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-12-02 11:36:09
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1022
'''


def main():
    N = int(input())

    l_title = {}
    l_author = {}
    l_keywords = {}
    l_publisher = {}
    l_year = {}
    l = [0, l_title, l_author, l_keywords, l_publisher, l_year]

    def readdata(d, k, v):
        if not d.get(k):
            d[k] = [v]
        else:
            d[k].append(v)

    for i in range(N):
        Id = int(input())
        title = input()
        readdata(l_title, title, Id)
        author = input()
        readdata(l_author, author, Id)
        keywords = input().split(' ')
        for each_keywords in keywords:
            readdata(l_keywords, each_keywords, Id)
        publisher = input()
        readdata(l_publisher, publisher, Id)
        year = input()
        readdata(l_year, year, Id)

    M = int(input())

    for i in range(M):
        q_origin = input()
        q = q_origin.split(':')
        order = int(q[0])
        key = q[1][1:]
        d = l[order]
        print(q_origin)
        if d.get(key):
            outputlist = sorted(d[key])
            for eachid in outputlist:
                print("%07d" % eachid)
        else:
            print("Not Found")


if __name__ == '__main__':
    main()
