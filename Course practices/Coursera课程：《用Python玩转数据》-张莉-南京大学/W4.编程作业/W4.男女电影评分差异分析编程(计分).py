#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-27 15:25:07
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
W4.编程作业: 男女电影评分差异分析编程(计分)
'''

import pandas as pd


def main():
    data = pd.read_table("u.data", sep='\t',
                         names=["user id", "item id", "rating", "timestamp"],
                         usecols=['user id', 'item id', 'rating'])
    user = pd.read_table("u.user", sep='|',
                         names=["user id", "age", "gender",
                                "occupation", "zip code"],
                         usecols=['user id', 'gender'])
    all_data = pd.merge(data, user)
    meanDataM = all_data[all_data.gender == 'M'].groupby(
        'user id').rating.mean().std()
    meanDataF = all_data[all_data.gender == 'F'].groupby(
        'user id').rating.mean().std()

    with open("result.txt", "w") as f:
        f.write("%.0f%.0f" % (meanDataM * 100, meanDataF * 100))


if __name__ == '__main__':
    main()
    # code
