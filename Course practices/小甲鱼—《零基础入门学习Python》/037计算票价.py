#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-26 13:13:50
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Price:
    price = 100
    weekend_ratio = 1.2
    child_discount = 0.5

    def __init__(self):
        while True:
            try:
                num_adult = int(input('请输入成人人数：'))
                num_child = int(input('请输入儿童人数：'))
                result = num_adult * self.price\
                    + num_child * self.price * self.child_discount
                day = input('是否周末（Y/N）？')
                if day in ['Y', 'y']:
                    result *= self.weekend_ratio
                break
            except ValueError:
                print('输入错误！')
        print('总价为：%.2f' % result)


Trip = Price()
print('''平价为：%.2f
周末价格为：%.2f
儿童折扣为：%.2f''' % (Trip.price,
                 Trip.price * Trip.weekend_ratio, Trip.child_discount))
