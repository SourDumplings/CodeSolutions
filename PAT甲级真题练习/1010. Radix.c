/*
 @Date    : 2017-11-28 13:47:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1010
思路来自：
http://blog.csdn.net/baidu_25107219/article/details/46700669
这个题目算是比较DT，花了很长时间，提交次数很多，每次都会有测试点没通过，后来网上搜索了一下，有一些特俗边界条件被我们忽略。
1，首先求目标数据进制，这个进制在任何条件下面都不能小于2，最大多少呢，不能局限于36，请想象多大都是有可能的，有多大，这么大！所以必须用long long int数据类型，这个一开始一直是被遗忘的角落。
2，由于数据搜索范围太大，穷举法一个for循环显然太慢了，肯定要超时的，最终就选则二分法查找。那么问题来了，二分法查找搜索上下边界是多少呢。这个好办，目标待求字符串的最小进制一定要比它所包含字符最大值还要大1，例如N2="456ad"，最大字符是'd'，所以最小应该是13+1=14,，这就对了吗？当然不对万一，我输入的N2="0"呢
最大字符'0'，然后0+1=1，这是不对的，最小值是2才对。那么它的上限是多少呢，上限当然不能超过另外一个数据的十进制大小，因为N2不为0情况下，最小个位数都是1，如果它的进制再超过N1的十进制数了的话，它在十进制下的数也就比N1还要大，不符合要求。
3，如果一开始，输入两个数据N2最小进制都比N1的十进制数据还要大的话，怎么办呢。N2最小进制的最大数据也就36，出现这种情况也就说明N1在十进制下肯定比36小，二分查找上限就不能是N1在十进制时候的数了，应该改为36。
几个特俗测试点容易被遗忘 0 0 1 100以及12 c 1 10
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>


long long GetValue(char N[], int l, long long radix)
{
    long long value = 0;
    int i;
    long long temp = 1;
    for (i = l - 1; i >= 0; i--)
    {
        if (isdigit(N[i]))
        {
            value += (N[i] - '0') * temp;
        }
        else
        {
            value += ((N[i] - 'a') + 10) * temp;
        }
        temp *= radix;
    }
    return value;
}

long long FindRadix(char *given, long long value_given, char *other, int lo)
{
    if (given[1] == '\0' && other[1] == '\0')
    {
        if (given[0] == other[0])
        {
            return GetValue(other, 1, 36) + 1;
        }
        else
        {
            return 0;
        }
    }
    long long r = value_given;
    long long temp = 1;
    long long value_other = 0;
    int i;
    long long r_up = value_given + 2;
    int r_down = 0;
    int m;
    for (i = 0; i < lo; i++)
    {
        m = GetValue(other+i, 1, 36);
        if (m > r_down)
        {
            r_down = m;
        }
        *(other + i) = m;
    }
    while (r <= value_given && r > 0)
    {
        value_other = 0;
        temp = 1;
        for (i = lo - 1; i >= 0; i--)
        {
            value_other += other[i] * temp;
            if (value_other > value_given)
            {
                // printf("$$This r = %lld is too large.$$\n", r);
                r_up = r;
                r = r / 2;
                break;
            }
            temp *= r;
        }
        if (value_other == value_given)
        {
            if (r <= r_down)
            {
                r++;
                if (r == r_up || r <= r_down)
                {
                    // 说明兜了一圈了没找到，或者还是达不到下界
                    break;
                }
            }
            return r;
        }
        else if (value_other < value_given)
        {
            // printf("$$This r = %lld is too small.$$\n", r);
            r++;
            if (r == r_up)
            {
                // 说明兜了一圈了没找到
                break;
            }
        }
    }
    return 0;
}

int main()
{
    char N1[11], N2[11];
    int tag;
    long long radix;
    scanf("%s %s %d %lld", N1, N2, &tag, &radix);
    long long value;
    char *given, *other;
    long long r;
    int l1 = strlen(N1);
    int l2 = strlen(N2);
    int lo;
    if (tag == 1)
    {
        value = GetValue(N1, l1, radix);
        given = N1;
        other = N2;
        lo = l2;
    }
    else
    {
        value = GetValue(N2, l2, radix);
        given = N2;
        other = N1;
        lo = l1;
    }
    // printf("given value is %lld\n", value);
    r = FindRadix(given, value, other, lo);
    if (r)
    {
        printf("%lld\n", r);
    }
    else
    {
        printf("Impossible\n");
    }
    return 0;
}

