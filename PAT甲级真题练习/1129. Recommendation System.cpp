/*
 @Date    : 2018-03-05 10:33:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1129
只要能存储前k个item的出现频率和值就行
如果当前recommend不足k个，那么往后添加一个新的即可
如果当前recomend已经有k个，只要将新的indice与最后一个进行比较与替换即可
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

static const int MAXN = 50001;
static map<int, int> itemFreq;

bool cmp(const int i1, const int i2)
{
    if (itemFreq[i1] == itemFreq[i2])
        return i1 < i2;
    return itemFreq[i1] > itemFreq[i2];
}

void insertion_sort(vector<int> &sortedData, int sorted_length, int p)
{
    int i;
    for (i = sorted_length; i != 0 && !cmp(sortedData[i-1], p); --i)
        sortedData[i] = sortedData[i-1];
    sortedData[i] = p;
    return;
}

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    int item;
    int query[MAXN];
    for (int i = 0; i != N; ++i)
        scanf("%d", &query[i]);
    vector<int> sortedData;
    for (int i = 0; i != N; ++i)
    {
        item = query[i];
        if (i != 0)
        {
            printf("%d:", item);
            int lastItemPos = find(sortedData.begin(), sortedData.end(), query[i-1]) -
                sortedData.begin();
            if (K != 0)
            {
                if (sortedData.size() < K)
                {
                    if (lastItemPos == sortedData.size())
                        sortedData.push_back(query[i-1]);
                    insertion_sort(sortedData, lastItemPos, query[i-1]);
                }
                else
                {
                    if (lastItemPos == K)
                    {
                        if (!cmp(sortedData.back(), query[i-1]))
                        {
                            sortedData.back() = query[i-1];
                            insertion_sort(sortedData, K-1, query[i-1]);
                        }
                    }
                    else
                        insertion_sort(sortedData, lastItemPos, query[i-1]);
                }
                for (auto it = sortedData.begin(); it != sortedData.end(); ++it)
                    printf(" %d", *it);
            }
            putchar('\n');
        }
        ++itemFreq[item];
    }
    return 0;
}

