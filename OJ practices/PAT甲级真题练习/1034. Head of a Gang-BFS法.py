

head = list(map(int, input().split()))

n = head[0]
k = head[1]

# print(head)

# 存储边
graph = {}
# 存储每个点的总通话时间
weight = {}


for i in range(n):
    line = input().split()
    a = line[0]
    b = line[1]
    value = int(line[2])
    if a not in graph:
        graph[a] = {}
    if b not in graph[a]:
        graph[a][b] = value
    else:
        graph[a][b] += value
    if b not in graph:
        graph[b] = {}
    if a not in graph[b]:
        graph[b][a] = value
    else:
        graph[b][a] += value
    if a not in weight:
        weight[a] = value
    else:
        weight[a] += value
    if b not in weight:
        weight[b] = value
    else:
        weight[b] += value

# print(graph)


def bfs():
    visit = {}

    # 每个结点初始化为未访问
    for key in graph.keys():
        visit[key] = 0

    flag = 0
    start = -1
    count = 0
    res = []
    while 1:
        flag = 0
        # 找到未访问的节点，记为start
        for key, value in visit.items():
            if value == 0:
                start = key
                flag = 1
                break
        # 如果没有未访问的节点了
        if flag == 0:
            break

        # 得到start的联通集作为列表l
        l = _bfs(start, visit)
        # 去除重复元素
        l = list(set(l))

        if len(l) > 2:
            summ = 0
            for each in l:
                summ += weight[each]
            if summ / 2 > k:
                count += 1
                rr = findhead(l)
                res.append((rr, len(l)))
    res.sort(key=lambda x: x[0])
    return (count, res)


def findhead(l):
    maxx = 0
    rr = '-1'
    for each in l:
        if weight[each] > maxx:
            maxx = weight[each]
            rr = each
    return rr


def _bfs(start, visit):
    # 将start所在的联通集作为列表返回（结点有可能重复）
    a = [start]
    # print(a)
    q = [start]
    while q != []:
        temp = []
        for each in q:
            visit[each] = 1
            for key in graph[each].keys():
                if visit[key] == 0:
                    temp.append(key)
                    a.append(key)
        q = temp
    # print(a)
    return a


r = bfs()
if r[0] == 0:
    print(0)
else:
    print(r[0])
    for each in r[1]:
        print(each[0] + ' %d' % (each[1]))
