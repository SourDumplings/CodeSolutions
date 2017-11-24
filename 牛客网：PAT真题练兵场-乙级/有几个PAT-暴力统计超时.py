#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-11-23 21:14:20
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.nowcoder.com/pat/6/problem/4066
'''


def main():
    s = input()
    l = len(s)
    count = 0

    for p in range(l):
        if s[p] == 'P':
            for a in range(p + 1, l):
                if s[a] == 'A':
                    for t in range(a + 1, l):
                        if s[t] == 'T':
                            count += 1

    result = count % 1000000007
    print(result)


if __name__ == '__main__':
    main()
