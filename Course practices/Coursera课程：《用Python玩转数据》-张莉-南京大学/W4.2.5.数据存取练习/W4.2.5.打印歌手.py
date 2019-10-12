#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-27 13:29:19
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
W4.2.5.数据存取练习，打印出歌手
'''

import pandas as pd


def main():
    data = pd.read_csv("data.csv")
    print(data.singer)
    return


if __name__ == '__main__':
    main()
    # code
