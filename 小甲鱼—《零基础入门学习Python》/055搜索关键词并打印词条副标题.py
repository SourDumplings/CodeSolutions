# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 055搜索关键词并打印词条副标题.py
@time: 2017/7/20 20:16

该爬虫允许用户输入搜索的关键词，可以进入每一个词条，然后检测该词条是否具有副标题，如有则将副标题一并打印出来
"""


import urllib.request as r
import urllib.parse as p
import re
from bs4 import BeautifulSoup

def main():
    keyword = input('请输入关键词：')
    keyword = p.urlencode({'word' : keyword})
    response = r.urlopen('http://baike.baidu.com/search/word?%s' % keyword)
    html = response.read()
    soup = BeautifulSoup(html, 'html.parser')

    for each in soup.find_all(href = re.compile('view')):
        content = ''.join([each.text])
        url2 = ''.join(['http://baike.baidu.com', each['href']])
        response2 = r.urlopen(url2)
        html2 = response2.read()
        soup2 = BeautifulSoup(html2, 'html.parser')
        if soup2.h2:
            content = ''.join([content, soup2.h2.text])
        content = ''.join([content, '->', url2])
        print(content)


if __name__ == '__main__':
    main()
