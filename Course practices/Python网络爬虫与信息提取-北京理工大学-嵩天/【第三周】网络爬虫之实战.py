# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 【第三周】网络爬虫之实战.py
@time: 2017/9/10 9:25

【第三周】网络爬虫之实战
"""

import requests
import re
from bs4 import BeautifulSoup
import traceback


# # 8 淘宝商品比价定向爬虫

# 获得页面的函数
# def getHTMLText(url):
#     try:
#         r = requests.get(url, timeout=30)
#         r.raise_for_status()
#         r.encoding = r.apparent_encoding
#         return r.text
#     except:
#         return ''
#
#
# # 对于每一个获得页面进行解析
# def parsePage(ilt, html):
#     try:
#         plt = re.findall(r'\"price\"\:\"[\d\.]*\"', html)
#         tlt = re.findall(r'\"title\"\:\".*?\"', html)
#         # print(plt)
#         for i in range(len(plt)):
#             price = eval(plt[i].split(':')[1])
#             title = eval(tlt[i].split(':')[1])
#             ilt.append([title, price])
#     except:
#         return ''
#
#
# # 将淘宝的商品信息输出到屏幕上
# def printGoodsList(ilt):
#     tplt = '{:^4}\t{:^20}\t{:^8}'
#     print(tplt.format('序号', '价格', '商品名称'))
#     count = 0
#     for q in ilt:
#         count = count + 1
#         print(tplt.format(count, q[0], q[1]))
#
#
# def main():
#     goods = '笔记本电脑'
#     depth = 3
#     start_url = 'https://s.taobao.com/search?q=' + goods
#     infoList = []
#
#     for i in range(depth):
#         try:
#             url = start_url + '&s=' + str(48 * i)
#             html = getHTMLText(url)
#             # print(html)
#             parsePage(infoList, html)
#         except:
#             continue
#
#     printGoodsList(infoList)


# 9 股票数据定向爬虫

# 获得url对应的页面
# def getHTMLText(url, code='utf-8'):
#     try:
#         r = requests.get(url)
#         r.raise_for_status()
#         r.encoding = code
#         # r.encoding = r.apparent_encoding
#         return r.text
#     except:
#         return ''
#
#
# # 获得股票的信息列表
# def getStockList(lst, stockURL):
#     html = getHTMLText(stockURL, 'GB2312')
#     soup = BeautifulSoup(html, 'html.parser')
#     # print(soup)
#     a = soup.find_all('a')
#     for i in a:
#         try:
#             href = i.attrs['href']
#             lst.append(re.findall(r'[s][hz]\d{6}', href)[0])
#         except:
#             continue
#
#
# # 获得每一支个股的股票信息并存储到数据结构
# def getStockInfo(lst, stockURL, fpath):
#     count = 0
#     # print(lst)
#     for stock in lst:
#         url = stockURL + stock + '.html'
#         html = getHTMLText(url)
#         try:
#             if html == '':
#                 continue
#
#             infoDict = {}
#             soup = BeautifulSoup(html, 'html.parser')
#             stockInfo = soup.find('div', attrs={'class': 'stock-bets'})
#             # print(stockInfo)
#             name = stockInfo.find_all(attrs={'class': 'bets-name'})[0]
#             # print(name)
#             infoDict.update({'股票名称': name.text.split()[0]})
#
#             keyList = stockInfo.find_all('dt')
#             valueList = stockInfo.find_all('dd')
#             for i in range(len(keyList)):
#                 key = keyList[i].text
#                 val = valueList[i].text
#                 infoDict[key] = val
#
#             with open(fpath, 'a', encoding='utf-8') as f:
#                 f.write(str(infoDict) + '\n')
#
#                 count += 1
#                 print('\r当前速度：{:.2f}%'.format(count * 100 / len(lst)), end='')
#         except:
#             count += 1
#             print('\r当前速度：{:.2f}%'.format(count * 100 / len(lst)), end='')
#             # traceback.print_exc() # 返回错误信息
#             continue
#
#
# def main():
#     stock_list_url = 'http://quote.eastmoney.com/stocklist.html'
#     stock_info_url = 'https://gupiao.baidu.com/stock/'
#     output_file = 'BaiduStockInfo.txt'
#     slist = []
#     getStockList(slist, stock_list_url)
#     # print(slist)
#     getStockInfo(slist, stock_info_url, output_file)


if __name__ == '__main__':
    main()
