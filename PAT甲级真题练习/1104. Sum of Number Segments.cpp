/*
 @Date    : 2018-02-23 11:55:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1104
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    double sum = 0;
    double num;
    for (int i = 1; i != N + 1; ++i)
    {
        scanf("%lf", &num);
        sum += static_cast<double>(i) * (N - (static_cast<double>(i) - 1)) * num;
    }
    printf("%.2f\n", sum);
    return 0;
}
