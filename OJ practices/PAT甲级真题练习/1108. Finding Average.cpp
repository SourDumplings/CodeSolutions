/*
 @Date    : 2018-02-26 11:26:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1108
思路来自：
https://www.liuchuo.net/archives/1924
sscanf() – 从一个字符串中读进与指定格式相符的数据
sprintf() – 字符串格式化命令，主要功能是把格式化的数据写入某个字符串中。
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int count = 0;
    char temp[50], numString[50];
    double num = 1001; // 一定要初始化，否则对于第一个不合法值其numString会很奇怪
    bool legal = true;
    double sum = 0;
    for (int i = 0; i != N; ++i)
    {
        legal = true;
        scanf("%s", temp);
        sscanf(temp, "%lf", &num);
        sprintf(numString, "%.2f", num);
        for (int j = 0; temp[j] != '\0'; ++j)
            if (temp[j] != numString[j])
            {
                legal = false;
                break;
            }
        if (num < -1000 || 1000 < num || !legal)
            printf("ERROR: %s is not a legal number\n", temp);
        else
        {
            ++count;
            sum += num;
        }

    }
    if (count == 0)
        printf("The average of 0 numbers is Undefined\n");
    else if (count == 1)
        printf("The average of 1 number is %.2f\n", sum);
    else
        printf("The average of %d numbers is %.2f\n",
            count, sum / (static_cast<double>(count)));
    return 0;
}
