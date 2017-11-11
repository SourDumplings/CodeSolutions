# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 【第二周】网络爬虫之提取.py
@time: 2017/9/1 10:12

【第二周】网络爬虫之提取
"""

import requests
from bs4 import BeautifulSoup
import bs4


# 6 中国大学排名爬虫

# 从网络上获取大学排名内容
def getHTMLText(url):
    try:
        r = requests.get(url, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ''


# 提取网页内容中信息到合适的数据结构
def fillUnivList(ulist, html):
    soup = BeautifulSoup(html, 'html.parser')
    tbody = soup.find('tbody')
    for tr in tbody.children:
        if isinstance(tr, bs4.element.Tag):
            TD = tr.find('td')  # tr标签下层是一个td标签，这个td标签里又包含了很多td标签,代码里我用用TD表示大td,用td表示内层td

            # print(TD.contents[0]) # TD标签的字符串内容包含了排名，即TD.contents[0]代表排名，

            tds = TD('td')  # 找到内层td，第一个td下层的div标签包含校名，第三个td包含成绩
            ulist.append([TD.contents[0], tds[0].div.string, tds[2].string])

    # 以下输出以清华大学为例，为大家打印标签的结构和内容
    # print(tbody.find('tr').prettify())
    # print(tbody.find('tr').contents[0].contents)  # contents[0]指的是tr下的TD

# 利用数据结构展示并输出结果
def printUnivList(ulist, num):
    tplt2 = '{0:^10}\t{1:{3}^10}\t{2:^2}'
    tplt1 = '{0:^9}\t{1:{3}^10}\t{2:^2}'
    print(tplt1.format('排名', '学校名称', '总分', chr(12288)))
    for i in range(num):
        u = ulist[i]
        print(tplt2.format(u[0], u[1], u[2], chr(12288)))


def main():
    uinfo = []
    url = 'http://www.zuihaodaxue.cn/zuihaodaxuepaiming2017.html'
    html = getHTMLText(url)
    fillUnivList(uinfo, html)
    printUnivList(uinfo, 20)  # 20 Univs


main()
