#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-20 09:54:01
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
W3.3.2.编程练习：创建DataFrame的编程小练习
'''

import pandas as pd
music_data = [("the rolling stones", "Satisfaction"), ("Beatles", "Let It Be"),
              ("Guns N' Roses", "Don't Cry"), ("Metallica", "Nothing Else Matters")]
music_table = pd.DataFrame(music_data)
music_table.index = range(1, 5)
music_table.columns = ['singer', 'song_name']
print(music_table)
