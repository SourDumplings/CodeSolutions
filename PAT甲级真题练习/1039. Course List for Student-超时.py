#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-12-06 16:05:13
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1039
'''


def main():
    temp = input().split(' ')
    N = int(temp[0])
    K = int(temp[1])

    students = {}

    for i in range(K):
        c_info = input().split(' ')
        c = int(c_info[0])
        n = int(c_info[1])
        if n:
            namelist = input().split(' ')
            for each_name in namelist:
                if each_name in students.keys():
                    students[each_name].append(c)
                else:
                    students[each_name] = [c]

    if N:
        query = input().split(' ')
        for each_name in query:
            if each_name not in students.keys():
                print("%s 0" % each_name)
                continue
            print("%s %d" % (each_name, len(students[each_name])), end='')
            students[each_name].sort()
            for each_course in students[each_name]:
                print(" %d" % each_course, end='')
            print()


if __name__ == '__main__':
    main()
