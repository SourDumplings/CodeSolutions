#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-11-23 19:04:50
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.nowcoder.com/pat/6/problem/4064
'''


def main():
    N = input()
    N = int(N)
    data = {}

    grade_list = input()
    grade_list = grade_list.split(' ')
    # print(grade_list)
    for i in range(N):
        grade = grade_list[i]
        grade = int(grade)
        if not data.get(grade):
            data[grade] = 1
        else:
            data[grade] += 1

    check = input()
    check = check.split(' ')
    check.pop(0)
    output = 0
    for each_check_grade in check:
        if data.get(int(each_check_grade)):
            n = data[int(each_check_grade)]
        else:
            n = 0
        if output:
            print(' ', end='')
        else:
            output = 1
        print(n, end='')
    print()


if __name__ == '__main__':
    main()
    exit(0)
