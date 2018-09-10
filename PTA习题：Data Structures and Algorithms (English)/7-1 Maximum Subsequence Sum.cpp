/*
 @Date    : 2018-09-07 12:12:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/663
 */

#include <iostream>
#include <cstdio>

using namespace std;

int K;

int main()
{
    scanf("%d", &K);
    int num[K];
    for (int i = 0; i != K; ++i)
        scanf("%d", &num[i]);
    int thisSum = 0, maxSum = 0;
    int thisFirstNum = num[0], resFirstNum = num[0], lastNum = num[K-1];
    bool allNeg = true;
    for (int i = 0; i < K; ++i)
    {
        thisSum += num[i];
        if (thisSum < 0)
        {
            thisSum = 0;
            thisFirstNum = i < K - 1 ? num[i + 1] : 0;
        }
        else if (thisSum > maxSum)
        {
            resFirstNum = thisFirstNum;
            lastNum = num[i];
            maxSum = thisSum;
        }
        if (allNeg && num[i] >= 0)
        {
            resFirstNum = lastNum = num[i];
            allNeg = false;
        }
    }
    printf("%d %d %d\n", maxSum, resFirstNum, lastNum);
    return 0;
}


