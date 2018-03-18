#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-09 09:54:58
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1073
'''


def main():
    sci = input()
    exp = int(sci.split('E')[1])
    dig = sci[1:].split('E')[0].replace('.', '')
    res = ''
    if exp >= 0:
        dotPos = exp + 1
        dig += (exp - len(dig) + 1) * '0'
        res += dig[:dotPos]
        res += '.'
        res += dig[dotPos:]
        if res[-1] == '.':
            res = res[:-1]
    else:
        res = "0." + (-exp - 1) * '0' + dig
    if sci[0] == '-':
        res = '-' + res
    print(res)
    return


if __name__ == '__main__':
    main()
    # code
