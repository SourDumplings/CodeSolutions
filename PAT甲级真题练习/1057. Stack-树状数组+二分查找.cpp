/*
 @Date    : 2018-01-31 13:18:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1057
利用树状数组实现了PeekMedian的要求，即利用树状数组实现了快速查找中位数的功能
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100001;
int c[MAX]; // 树状数组，下标对应key（在栈中存的值），
// 每个元素记录的是其叶子节点这个值（下标）在栈中的总数

int lowbit(int x)
{
    return x & (-x);
}

int sum(int pos)
{
    int result = 0;
    while (pos)
    {
        result += c[pos];
        pos -= lowbit(pos);
    }
    return result;
}

void add(int pos, int value)
{
    while (pos <= MAX)
    {
        c[pos] += value;
        pos += lowbit(pos);
    }
    return;
}

// 传给find的value是所需中位数在所有数中是第几个
int find(int value)
{
    int l = 0, r = MAX - 1, median, res;
    while (l < r - 1)
    {
        if ((l + r) & 1)
            median = (l + r - 1) / 2;
        else
            median = (l + r) / 2;
        // res即为median（树状数组的元素下标）这个数在栈中是第几个（按最后一个key计数）
        res = sum(median);
        // printf("l = %d r = %d median = %d res = %d value = %d\n", l, r, median, res, value);
        // 判断二分查找区间缩小的够不够
        // 刚开始肯定是res >= value的，一旦res小于了value就意味着median这个数小于所需的中位数了
        // 即最终要找到想要的中位数-1的那个数的最后一个是第几个，再加一即为所需的结果中位数
        if (res < value)
            l = median;
        else
            r = median;
    }
    return l + 1;
}

int main(int argc, char const *argv[])
{
    memset(c, 0, sizeof(c));
    char order[10];
    int stack[MAX], top = 0, N, pos;
    scanf("%d\n", &N);
    while (N--)
    {
        scanf("%s", order);
        if (order[1] == 'u')
        {
            scanf("%d", &pos);
            stack[top++] = pos;
            add(pos, 1);
        }
        else if (order[1] == 'o')
        {
            if (top)
            {
                int out = stack[--top];
                add(out, -1);
                printf("%d\n", out);
            }
            else
                printf("Invalid\n");
        }
        else if (order[1] == 'e')
        {
            if (!top)
                printf("Invalid\n");
            else
            {
                int res;
                if (top & 1)
                    res = find((top+1)/2);
                else
                    res = find(top/2);
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
