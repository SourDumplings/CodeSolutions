/*
 @Date    : 2017-11-24 09:11:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.nowcoder.com/pat/6/problem/4066

思路来自：http://www.jianshu.com/p/65291de1906b
每个A对应的PA组合数量是A之前P的数量，
每个T对应的PAT组合数量是T之前所有A对应的PA组合数量的累加，
所有的PAT组合数量是所有T对应的PAT组合数量的累加

然后证明一下这个magic number——1000000007为什么是这个数（大概等于）以及什么时候应该取模：
我们用有符号32位整型来计数，按照我代码里的变量名：P、PA、PAT。

P每次自增1，因此最大会达到10^5，不需取模。
PA每次累加P的值，我们来看一个比较极端的情况：
"PAPA ... (共50000对PA) ... PA"，这样记录PA的组合数量，就是
PA=1 + 2 + 3 + ... + 50000=2500050000，就已经大于int了，因此计算PA应该取模。
PAT每次累加PA的值，因此两个值都会比较大，必须要取模。累加之后（取模之前）的数会小于2000000013，这个值小于int的最大值2^31-1=2147483647，不会溢出（模取得过大就会在没来得及取模之前就溢出了，我觉得这是关键）。
那用unsigned int呢，PA是不是不需要取模了？我觉得是的。
这道题是要检查答案的，用一个素数做模应该有避免巧合答案的考虑。
 */

#include <stdio.h>

#define MAX 100000
#define LIM 1000000007

int main()
{
    char s[MAX+1];
    gets(s);
    int PA, PAT, result;
    result = PA = PAT = 0;
    int i;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == 'P')
        {
            PA = (PA + 1) % LIM;
        }
        else if (s[i] == 'A')
        {
            PAT = (PAT + PA) % LIM;
        }
        else if (s[i] == 'T')
        {
            result = (result + PAT) % LIM;
        }
    }
    printf("%d\n", result);
    return 0;
}

