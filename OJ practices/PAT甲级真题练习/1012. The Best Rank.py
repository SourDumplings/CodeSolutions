#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-11-28 19:18:52
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
https://www.patest.cn/contests/pat-a-practise/1012
'''


def main():
    temp = input()
    temp = temp.split(' ')
    N = int(temp[0])
    M = int(temp[1])

    Agrade = {}
    Cgrade = {}
    Mgrade = {}
    Egrade = {}

    for i in range(N):
        s = input()
        s = s.split(' ')
        ID = s[0]
        C = int(s[1])
        m = int(s[2])
        E = int(s[3])
        A = (C + m + E) / 3
        Agrade[ID] = A
        Cgrade[ID] = C
        Mgrade[ID] = m
        Egrade[ID] = E

    def readrankdata(rankdata, ranklist, index, N):
        r = 1
        # print(ranklist)
        count = 0
        for i in range(N):
            if not rankdata.get(ranklist[i][0]):
                rankdata[ranklist[i][0]] = [0, 0, 0, 0]
            rankdata[ranklist[i][0]][index] = r
            count += 1
            if i < N - 1 and ranklist[i][1] > ranklist[i + 1][1]:
                r += count
                count = 0
        # print(rankdata)
        return

    rankdata = {}  # id : [Arank, Crank, Mrank, Ernak]
    A_ranklist = sorted(Agrade.items(), key=lambda d: d[1], reverse=True)
    readrankdata(rankdata, A_ranklist, 0, N)
    C_ranklist = sorted(Cgrade.items(), key=lambda d: d[1], reverse=True)
    readrankdata(rankdata, C_ranklist, 1, N)
    M_ranklist = sorted(Mgrade.items(), key=lambda d: d[1], reverse=True)
    readrankdata(rankdata, M_ranklist, 2, N)
    E_ranklist = sorted(Egrade.items(), key=lambda d: d[1], reverse=True)
    readrankdata(rankdata, E_ranklist, 3, N)

    items = ['A', 'C', 'M', 'E']
    bestrankdata = {}  # id : [bestrank, best]
    for each in rankdata:
        bestrank = rankdata[each][0]
        for each_rank in rankdata[each]:
            if each_rank < bestrank:
                bestrank = each_rank
        best = rankdata[each].index(bestrank)
        if not bestrankdata.get(each):
            bestrankdata[each] = [0, 0]
        bestrankdata[each][0] = bestrank
        bestrankdata[each][1] = best

    # print(bestrankdata)

    checklist = []
    for i in range(M):
        temp = input()
        # print(temp)
        checklist.append(temp)
    # print(checklist)

    for each_id in checklist:
        data = bestrankdata.get(each_id)
        if data:
            print("%d %s" % (data[0], items[data[1]]))
        else:
            print("N/A")


if __name__ == '__main__':
    main()
