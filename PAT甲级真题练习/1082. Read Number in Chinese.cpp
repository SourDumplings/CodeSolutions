/*
 @Date    : 2018-02-16 10:52:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1082
 */

#include <iostream>
#include <cstdio>

using namespace std;

static char NUM[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

void process_four_digit_num(int num)
{
    int q = num / 1000;
    if (q)
    {
        printf("%s Qian", NUM[q]);
        num %= 1000;
        if (num)
        {
            if (num < 100)
                printf(" ling");
            putchar(' ');
        }
    }
    int b = num / 100;
    if (b)
    {
        printf("%s Bai", NUM[b]);
        num %= 100;
        if (num)
        {
            if (num < 10)
                printf(" ling");
            putchar(' ');
        }
    }
    int s = num / 10;
    if (s)
    {
        printf("%s Shi", NUM[s]);
        num %= 10;
        if (num)
            putchar(' ');
    }
    if (num)
        printf("%s", NUM[num]);
    return;
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    if (num == 0)
        printf("ling");
    else
    {
        if (num < 0)
        {
            printf("Fu ");
            num = -num;
        }
        if (num >= 100000000)
        {
            int y = num / 100000000;
            printf("%s Yi", NUM[y]);
            num %= 100000000;
            if (num)
            {
                if (num < 10000000)
                    printf(" ling");
                putchar(' ');
            }
        }
        if (num >= 10000)
        {
            int w = num / 10000;
            process_four_digit_num(w);
            printf(" Wan");
            num %= 10000;
            if (num)
            {
                if (num < 1000)
                    printf(" ling");
                putchar(' ');
            }
        }
        process_four_digit_num(num);
    }
    putchar('\n');

    return 0;
}
