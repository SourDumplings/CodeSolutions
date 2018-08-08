/*
 @Date    : 2018-08-06 21:51:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805343236767744
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
vector<bool> prime(MAX);

int main(int argc, char const *argv[])
{
    fill(prime.begin(), prime.end(), true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX; ++i)
    {
        if (prime[i])
        {
            for (int j = i * 2; j < MAX; j += i)
            {
                prime[j] = false;
            }
        }
    }

    int maxSize, n, m;
    scanf("%d %d %d", &maxSize, &n, &m);

    while (!prime[maxSize])
    {
        ++maxSize;
    }

    vector<int> table(maxSize);
    fill(table.begin(), table.end(), 0);

    int key;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &key);
        int h = key % maxSize, j, k;
        for (j = 0, k = h; j <= maxSize; ++j, k = (h + j * j) % maxSize)
        {
            if (table[k] == 0)
            {
                table[k] = key;
                break;
            }
        }
        if (j > maxSize)
        {
            printf("%d cannot be inserted.\n", key);
        }
    }

    int t = 0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &key);
        int h = key % maxSize;
        for (int j = 0, k = h; j <= maxSize; ++j, k = (h + j * j) % maxSize)
        {
            ++t;
            if (table[k] == 0 || table[k] == key)
            {
                break;
            }
        }
    }

    printf("%.1f\n", (double)t / m);
    return 0;
}

