#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-13 17:22:08
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


contact = {}

print('''|--- 欢迎进入通讯录程序---|
|--- 1 ：查询联系人资料 ---|
|--- 2 ：插入新的联系人 ---|
|--- 3 : 删除已有联系人 ---|
|--- 4 : 退出通讯录程序 ---|\n''')

while 1:
    order = int(input('请输入相关指令代码：'))

    if order == 2:
        name2 = input('请输入联系人姓名：')
        if name2 in contact:
            print('您输入的用户名在通讯录中已存在！')
            print(name2, '：', contact[name2])
            edit = input('是否修改该用户的资料？（Yes/No）')
            if (edit != 'Yes') and (edit != 'No'):
                print('输入错误！')
            elif edit == 'Yes':
                contact[name2] = input('请输入用户联系电话：')
                print('修改成功！')
            else:
                continue
        else:
            phone2 = input('请输入用户联系电话：')
            contact[name2] = phone2
            print('插入成功！')

    if order == 1:
        name1 = input('请输入联系人姓名：')
        if name1 in contact:
            print(name1, '：', contact[name1])
        else:
            print('该联系人不存在！')

    if order == 3:
        name3 = input('请输入联系人姓名：')
        if name3 in contact:
            contact.pop(name3)
            print('删除成功！')
        else:
            print('该联系人不存在！')

    if order == 4:
        break

print('|--- 感谢使用通讯录程序 ---|')
