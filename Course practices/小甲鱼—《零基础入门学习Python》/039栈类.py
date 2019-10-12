#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-28 18:38:50
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Stack:

    def __init__(self):
        self.content = []

    def base(self):
        return self.content[0]

    def push(self, each):
        self.content.append(each)

    def top(self):
        return self.content[len(self.content) - 1]

    def pop(self):
        end = self.content.pop()
        return end

    def isEmpty(self):
        if len(self.content):
            return False
        else:
            return True


a = Stack()
print(a.isEmpty())
print(a)
a.push(1)
print(a.isEmpty())
a.push('2')
a.push('x')
print(a.base())
print(a.top())
print(a.pop())
print(a.top())
a.push('y')
print(a.top())
print(a.base())
a.pop()
a.pop()
a.pop()
print(a.isEmpty())
