#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-26 16:28:40
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
在此处添加文件说明
'''

import numpy as np
import pandas as pd


dates = pd.date_range('20171001', periods=10)
listA = ['value']
result = pd.DataFrame([x for x in range(1, 11)], index=dates, columns=listA)

print(result)
