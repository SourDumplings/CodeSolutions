/*
 @Date    : 2018-02-14 18:26:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1078
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

bool is_prime(int num)
{
    if (num == 2)
        return true;
    else if (num == 1 || num % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int next_prime(int num)
{
    int p;
    for (p = num; !is_prime(p); ++p);
    return p;
}

int quadratic_probing(vector<bool> &table, int MSize, int num)
{
    int h = num % MSize;
    if (table[h] == false)
    {
        table[h] = true;
        return h;
    }
    int pos = -1;
    for (int d = 1; abs(d) <= MSize / 2; ++d)
    {
        int tryPos = (h + (d * d)) % MSize;
        if (table[tryPos] == false)
        {
            pos = tryPos;
            table[pos] = true;
            break;
        }
    }
    return pos;
}

int main(int argc, char const *argv[])
{
    int MSize, N;
    scanf("%d %d", &MSize, &N);
    MSize = next_prime(MSize);
    vector<bool> table(MSize);
    map<int, int> posData;
    fill(table.begin(), table.end(), false);
    int num;
    vector<int> inputSeq;
    while (N--)
    {
        scanf("%d", &num);
        inputSeq.push_back(num);
        int pos = quadratic_probing(table, MSize, num);
        posData.insert(make_pair(num, pos));
    }
    int output = 0;
    for (auto i : inputSeq)
    {
        if (output++)
            putchar(' ');
        if (posData[i] != -1)
            printf("%d", posData[i]);
        else
            putchar('-');
    }
    putchar('\n');
    return 0;
}
