# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 055打印包含view关键字的链接.py
@time: 2017/7/20 19:47

打印包含view关键字的链接
"""

from bs4 import BeautifulSoup
import urllib.request as r
import re


def main():
    url = 'http://baike.baidu.com/view/284853.htm'
    response = r.urlopen(url)
    html = response.read()

    soup = BeautifulSoup(html, "html.parser")
    # print(soup)

    for each in soup.find_all(href = re.compile('view')):
        print(each.text, '->', ''.join(['http://baike.baidu.com',
                                        each['href']]))


if __name__ == '__main__':
    main()